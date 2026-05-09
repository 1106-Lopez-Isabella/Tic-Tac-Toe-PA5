Tic-Tac-Toe project for CS 202 by Isabella Lopez and Reena Bagchi 
Date: 5/8/2026
Name: Tic-Tac-Toe
How to compile: In terminal type make and then push the enter key to compile. 
How to play: After compiling type "./game playerData.txt" without the quotes in the terminal and press enter to run the game.
you will then be prompted, follow the prompts. You can exit anytime by typing "0" (without quotes) and pushing enter. Make sure you put BOTH row and colum entries when prompted for the game to work correctly. If you start a new game, your information will be lost.

For reference, here is the layout of the 3X3 board (row)(column):

| (1)(1) | (1)(2) | (1)(3) |

| (2)(1) | (2)(2) | (2)(3) |

| (3)(1) | (3)(2) | (3)(3) |


Class structure: We have 4 classes: the user class (assigns names and chooses symbols for players) which is our abstract base class and a parent class for our computer and player classes (both inherit from user and then make moves depending on which spots of the board is open) and then our board class which controls the board.

Extra libraries used:
* Name: cstdlib
* A C++ Standard Library 

* Name: fstream
* A C++ Standard Library 

