**Isolation**
This is a spooky scavenger hunt game built in Unreal Engine 5.4, coded and scripted solo, by Dominic Hughes.

**Idea**
This was a game-jam project with the theme "Isolation", which made me think of a lighthouse, which became the main inspiration for the game. 

**Process**
I began working on the game by building a basic first person character in C++, and then moved on to building a lighthouse that consumes fuel and the player has to refill. To do this I built an interaction system using a collision box attached to the player that calls an interact function through a C++ interface on an Interactable. With only a small number of interactables I hardcoded interactions rather than generalising them which can be seen in the Interact function on the player character, this solution is still versatile enough to add more interactables, which of course came later.
After I had the ligthouse working as desired I began working on the level the player will exist in. I created a heightmap in GIMP and imported it as a landscape to Unreal. I did a small bit of modelling in Unreal to create the ligthouse structure, but then populated the level using an assetpack called Fantastic Village by Tidal Flask. 
Once the level was completed I started work on Relics, which becomes the main focus of the game. The player must seek them to win while still maintaining the ligthouse. Adding these was very simple thanks to my interaction interface previously mentioned and required only a few lines of code added to the character.

**UI**
I built the UI in Unreals editor and created custom functions to display information like lighthouse fuel level to the player. The UI Works entirely with Blueprint, however it is C++ events that update the blueprint, called from:
Character -> Controller -> UI

**PlayTesting**
I had a few friends help me with playtesting, at first the game was too hard and fast paced so I dramatically reduced the fuel consumption if the lighthouse and reduced the players move speed by half. This hugely improved the player experience, however presented the opportunity for a sprint function, as the player sometimes couldn't fix this lighthouse in time. 
I added a sprint/stamina abilities to the game, which can be seen on the character cpp file as "StaminaTick" and "TiredTick". I implemented the ability similar to Zelda Breath of the Wild, which complements gameplay and shows the player their stamina right in the middle of the screen. 
