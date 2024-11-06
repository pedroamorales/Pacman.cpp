# Pacman
1. This project is a Pacman game based on the original.
 
## Setup
1. Clone this project inside an OpenFrameworks installation's "apps/myApps/" directory
2. Run the command "make" in the terminal or the "Build" Task in VSCode.
3. To run the project using the included debug configurations you must open the "launch.json" file
found in ".vscode/". In "launch.json" change the "program" attribute for the corresponding configuration (according to your OS)
to reflect the path to your executable. The executable will have the same name as this repository, and if on Windows, it 
will end in ".exe"

## Game Guide
1. The game starts off with a Choose Character Menu, unfortunately, the choose character method does not work yet. Feel free to pick any character because it has no effect. Currently, Mrs Pacman appears as the default character.

2. After choosing the characters, press start and play an original copy of Pacman.

## PowerUps Guide
After a PowerUp is eaten, press the spacebar to activate it, if not, it is saved in the PowerUps bar.
  
### Apple Power-Up:
- Gives Pacman a speed boost for 5 seconds.

### Strawberry Power-UP:
- Makes Pacman invisible and unkillable for 5 seconds. 

### Cherry Power-Up:
- Teleports Pacman to a random dot in the map.
