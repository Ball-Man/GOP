# GOP
Gioco dell'Oca Pazza

### Compile
To compile the project, use:
```
make
```
It should work perfectly on both unix and windows systems.

### Before starting
Warning: the three files:
* squares.mx
* cards.mx
* gop.txt

Must be in the directory from where the game is played.
Since a copy of these files is already in present in the root directory of the project and since the binaries are built in a specific directory called 'build', I encourage playing the game from the root, with:
```
./build/gop
```
on unix systems, or with:
```
build\gop.exe
```
on windows systems.

### How to play
The game is quite simple to understand. Just run the application and follow the instruction. At first the game will ask you how many players are playing the game, their names and symbols(characters used to keep track of the players on the gameboard, a kind of pawn). After that, the rules are simple:
* use 'die' to roll the dice.
* use 'quit' to quit the game.
* use ENTER to continue when the game waits for you to read.

The first one who reaches the end of the gameboard, wins.

### More info
More info about the project developement can be found in [the wiki section of this repository.](https://github.com/Ball-Man/GOP/wiki)