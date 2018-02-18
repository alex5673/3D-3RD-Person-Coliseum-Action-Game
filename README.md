# 3D-3rd-Person-Coliseum-Action-Game

3rd year Advanced Games Technology project.

C++ action/melee game based in a coliseum where the player aims to eliminate all the enemies within the coliseum. Developed in Microsoft Visual Studio, with OpenGL used for Graphics.

For this game demo I wanted to create a game that would be suited towards beign a wave based game, where all the action takes place is a
confined area (the coliseum), in which the player would see how many waves of the enemies the player could survive. Since this is a demo
there is only one wave of enemies but the demo showcases the concept for the game plus it showcases the features I have implemented.

The game is implemented from an intial template provided for me. I have used OpenGL for a graphics API, using a combination of static
meshes for obstacles and dynamic messhes for characters and enemies, as well as primitative objects that make items such as powerups and
environment altering special effects. Both the chacraters and enemies have animations that are used at certain times and I have implmented
basic physics for the movement and actions of the characters and enemies. The character has a jump action which uses gravity and mass
calculations as well as a forward movement motion which also uses force and mass calculations. The bullets fired by the enemy similarly use
this basic physics. The most complecated shape that I made from primitative shapes was a sword powerup (which enhances strength) - the
sword powerup was made up of a polygon and 3 squares. The shape is also properly lit with vector normals provided, as well as each of the
shapes making up the overall sword shape being textured mapped to look like a katana.

The enemies use a finite state machine to implement basic AI behaviour, whereby the nearest enemy shoots at the player, and if the player
is near enough to an enemy the enemy will move towards the player and attempt to melee them. From the player's point of view, the player
has to avoid the bullets fired by the enemy and aim to melee the enemy until the enemy is defeated.

Simple audio is implemented to add background noise as well as pickup noises. A start menu is also implemented in which the player can see
the controls for the game, as well as choose different difficulties (that alter the enemy strength).
