#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "State.h"
#include "Cherry.h"
#include "Strawberry.h"
#include "Apple.h"
#include "CherryPowerup.h"
#include "StrawberryPowerUp.h"
#include "ApplePowerUp.h"

Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height) {
    spawnX = x;
    spawnY = y;
    DotsEaten = 0;
    DotCount = 0;
    sprite.load("images/pacman.png");    
    sprite.load("images/mrspacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;

    for (int i=0; i<3; i++) {
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for (int i=0; i<3; i++) {
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for (int i=0; i<3; i++) {
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for (int i=0; i<3; i++) {
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }

    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;

    moving = MLEFT;
    
}

void Player::tick() {

    checkCollisions();

    if (moving == MUP && canMoveUp) 
        facing = UP;
    else if (moving == MDOWN && canMoveDown) 
        facing = DOWN;
    else if (moving == MLEFT && canMoveLeft) 
        facing = LEFT;
    else if (moving == MRIGHT && canMoveRight)
        facing = RIGHT;

    if(facing == UP && canMoveUp){
        y-= speed;
        walkUp->tick();
    }else if(facing == DOWN && canMoveDown){
        y+=speed;
        walkDown->tick();
    }else if(facing == LEFT && canMoveLeft){
        x-=speed;
        walkLeft->tick();
    }else if(facing == RIGHT && canMoveRight){
        x+=speed;
        walkRight->tick();
    }
    if(invisCounter < 0){
        this->renderEntity = true;
        this->isKillable = true;
        this->unkillableTimer = 30*10;
    }
    if(increasedSpeedTimer == 0) {
        this->speed = 4;
    }
}

void Player::render() {
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());

    if(facing == UP)
        walkUp->getCurrentFrame().draw(x, y, width, height);
    else if(facing == DOWN)
        walkDown->getCurrentFrame().draw(x, y, width, height);
    else if(facing == LEFT)
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    else if(facing == RIGHT)
        walkRight->getCurrentFrame().draw(x, y, width, height);
    
    ofSetColor(256, 0, 0);
    ofDrawBitmapString("Health: ", ofGetWidth()/2 + 100, 50);

    for(unsigned int i=0; i<health; i++){
        ofDrawCircle(ofGetWidth()/2 + 25*i +200, 50, 10);
    }

    ofDrawBitmapString("Score:"  + to_string(DotCount), ofGetWidth()/2-200, 50);

    string pws = "Powerups: ";
    for(Powerup* p: powerupList) {
        pws += p->toString();
        pws += ", ";
    } 
    pws.erase(pws.begin() + pws.length()-1);
    ofDrawBitmapString(pws, ofGetWidth()/2-200,  ofGetHeight()-50);
}

void Player::keyPressed(int key) {
    switch(key) {
        case 'w':
            moving = MUP;
            break;
        case 's':
            moving = MDOWN;
            break;
        case 'a':
            moving = MLEFT;;
            break;
        case 'd':
            moving = MRIGHT;;
            break;
        case 'n':
            die();
            break;
        case 'm': // Check for Max Health - Noel
            if (health < 3) {
               health++; 
            }
            break;
        case ' ':
            if(powerupList.size() > 0) {
                powerupList[0]->em = this->em;
                powerupList[0]->activate();
                powerupList.erase(powerupList.begin());
            }
            break;
    }
}

void Player::keyReleased(int key) {
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}

void Player::mousePressed(int x, int y, int button) {

}

int Player::getHealth(){ return health; }
int Player::getScore(){ return score; }
FACING Player::getFacing(){ return facing; }
void Player::setHealth(int h){ health = h; }
void Player::setFacing(FACING facing){ this->facing = facing; }
void Player::setScore(int h){ score = h; }

void Player::checkCollisions() {
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;
    CurrentDotCount();

    for(BoundBlock* boundBlock: em->boundBlocks) {
        if(this->getBounds(x, y-speed).intersects(boundBlock->getBounds()))
            canMoveUp = false;
        if(this->getBounds(x, y+speed).intersects(boundBlock->getBounds()))
            canMoveDown = false;
        if(this->getBounds(x-speed, y).intersects(boundBlock->getBounds()))
            canMoveLeft = false;
        if(this->getBounds(x+speed, y).intersects(boundBlock->getBounds()))
            canMoveRight = false;
    }

    for(Entity* entity:em->entities) {
        if (collides(entity)) {
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)) {
                entity->remove = true;
                score += 10;
                DotsEaten++;
                DotsEaten = DotsEaten/2;
            }
            if(dynamic_cast<BigDot*>(entity)) {
                score +=20;
                em->setKillable(true);
            }
            if(dynamic_cast<BigDot*>(entity)){
                score +=20;
                em->setKillable(true);
                this->isKillable = false;
            }
            if(dynamic_cast<Cherry*>(entity)){
                powerupList.push_back(new CherryPowerup(this));
                entity->remove = true;
            }
            if(dynamic_cast<Strawberry*>(entity)){
                //strawberry collision
                powerupList.push_back(new StrawberryPowerup(this));
                entity->remove = true;
            }
            if(dynamic_cast<Apple*>(entity)){
                //apple collision
                powerupList.push_back(new ApplePowerup(this));
                entity->remove = true;
            }
        }
    }
    
    for(Entity* entity:em->ghosts) {
        if (collides(entity)) {
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if(ghost->getKillable())
                ghost->remove = true;
            else
                die();
        }
    }    
}

void Player::die() {
    health--;
    x = spawnX;
    y = spawnY;
}

Player::~Player() {
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}

int Player::CurrentDotCount() {
    DotCount = 0;
    for(Entity* entity:em->entities){
        if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                DotCount += 1;
                
            }
    }
    DotCount -= DotsEaten;
    return DotCount;
}