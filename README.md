# A-simple-Battleship-game

Tasks<br /> <br /> 
Design the set of classes for the Battleship game. The object of the game is to sink the opponent's ship with as few shots as possible.<br /> <br /> 
The rows of the table are indexed with numbers, and the columns with letters, and each square will be specified by its coordinates: (a, 2), (c, 7), etc.<br /> <br /> 
Six types of ships can be placed on the game board, consisting of one or more adjacent squares, one of which represents the center of rotation.<br /> <br /> 
A maximum of one instance of each ship may be added to the game board, but it must not overlap or be adjacent. After each landing of a ship, it may eventually rotate around
center of rotation to the left or right.<br /> <br /> 
After the first player has placed his ships on the game board, the second player must sink them by successive blows.<br /> <br /> 
For each shot, the target square will be specified. If a ship has been hit, that square will be marked as the correct, otherwise wrong shot.<br /> <br /> 
When all the squares of a ship have been hit, the ship is considered sunk and will appear on the game board.<br /> <br /> 
In addition, for each good shot, the player receives 100 points, and for a missed one, 50 points will be deducted.<br /> <br /> 
At the end, the player's score will also be displayed. A board will be designed for the game board, and for ships a hierarchy of classes (with an abstract base class) that uses polymorphism. Game board knows the ships it contains, but not their positions, so when specifying a square of to a player, she must interrogate the ships to find out if a ship has been hit or not. Communication between the game board and ships is done through messages, so each ship must store a pointer to the game board to simplify communication.<br /> <br /> 

There are supposed to be two game modes:<br /> <br /> 

a) interactive, in which players place their ships, and then they strike alternately;<br /> 

b) sequentially, in which alternately, one player places his ships and the other tries to sink them.<br /> <br /> 

The commands allowed in the game are:<br /> 
- Place - place a ship on the game board<br /> 
- Rotate - rotates the ship<br /> 
- Remove - removes a ship from the game board<br /> 
- Play - the command to start the game<br /> 
- Quit - forced termination of the game<br /> 
- Save - save the game configuration to the file (all classes must have a save method)<br /> 
- Load - load a previously saved game into memory<br /> 
- Help - display game controls<br /> 
