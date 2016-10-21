One Dead Dodo 
presents 
Wreckingball Rampage.


Global Game Jam 2010
31/01/2010

Created by

David Fletcher
Oliver Brown
Stephen Wilson
Matthew McCaffery

///////////////////////////////////////////////////


/*To Install/Run Game*/

1. Unzip the Wreckingball Rampage.zip file.
2. Open the file and navigate to the Release file.
3. Double click on the .exe file to run the game.

// if audio problems persist

In the release file load the oalinst.exe to install the audio liberies.


/*Objective*/

The object of the game is to achieve the highest score possible within 5 minutes through the destruction of buildings.




/*Gameplay*/

The game consists of a rotating world which is host to tanks and buildings and a bouncing ball which is controlled by the player. 
- Buildings are destructable and will earn you score
o	The structure of the buildings is damaged and destroyed at the point of impact
o	One point per surface element destroyed
o	Points are multiplied by combo multiplier

- Tanks shoot projectiles at the ball, the explosion of which will decrease your score
o	Up to 50 points are removed from the score, dependant on the distance from the explosion
o	The explosion also applies force to the ball, which can send it off in a different direction
o	Tanks can be destroyed by being hit, but do not add to score. The trade off for focusing on destroying the tanks so as to preserve score is that this can take more time than it would to earn more points within the time limit. 




/*Control*/

The single interaction with the game consists of being able to control the direction and force applied to the ball. 
- To move the ball, drag the mouse cursor across the screen
- The red line drawn on screen indicates the length and direction that the ball will be sent in
- The longer the line is drawn, the faster the ball will travel when the cursor is released




/*Multipliers*/

Multipliers are applied to score when you hit, and destroy, a building’s surface after bouncing off the edges of the screen.

- The score multiplier is doubled for each consecutive edge hit
- Edges can only double the multiplier once, with the 3 edges that exist this brings the total possible score multiplier to 8
- The multiplier is reset to 1 when the player drags the ball
- The multiplier is reset to 1 when the ball bounces off the floor
