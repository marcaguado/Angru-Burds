# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting 01.11.2021 16::00

**Participants**: 
1. Marc
2. Roope
3. Laura
4. Venla 

## Summary of works
1. Everybody had written their part in the project plan. Some final touches still need to be done before it can be submitted. We agreed that this week should be used for familiarizing ourselves with Qt and Box2D. Marc had watched videos on game development with Qt.

## Challenges

1. We were a bit confused about how to implement different levels to the game. 
2. Venla is overwhelmed by the libraries.

## Actions
1. Marc is going to finish his part on the project plan and look into Qt and maybe try using GitLab.
2. Roope is is going to finish his part on the project plan and look into Box2D.
3. Laura is is going to finish her part on the project plan and look into Box2D.
4. Venla is going to finish her part on the project plan and look into Qt.

> The next meeting is held on Monday 8.11. at **14:00**.

## Project status 
Project has not really started yet. 

### TODOs
1. No additional TODOs this time.


# Meeting 08.11.2021 14::00

**Participants**: 
1. Marc
2. Roope
3. Laura
4. Venla 

## Summary of works
1. We used this past week to familiarize ourselves with the enviroment we will be working in. Some of us tried some stuff with Qt, some of us looked into Box2D and some of us decided on the art style (pixel art). We also practiced using GitLab.

## Challenges

1. We are still a bit confused on how we are going to bring it all together into a game, but we're working on finding it out. 

## Actions
1. Marc is going to start working on the technology behind the level making.
2. Roope is going to start working on the main.cpp, which is going to be the core of the game.
3. Laura is going to look more deeply into Box2D, she'll try to have a basic example working by next meeting.
4. Venla is going to draw the birds we'll be using in the game.
> The next meeting is held on Monday 15.11. at **14:00**.

## Project status 
Project has not really started yet, we have mostly familiarized ourselves with the tools before starting to work on the project.

### TODOs
1. No additional TODOs this time.


# Meeting 15.11.2021 14::00

**Participants**:
1. Marc
2. Roope
3. Laura
4. Venla

## Summary of works
1. Roope showed the group a simple program he had done during the week. The program used Box2D to create a box and a platform, and the box could "jump" forward and collide with the corner of the platform. Roope had also created a basic structure for some of the classes needed for the project.
2. Venla had created graphics for two different kind of birds.
3. Marc had worked with the level loader module.
4. Laura finally got her VSCode to work correctly and focused on the required libraries.

## Challenges
1. We weren't yet sure which is the best way to implement all the different types of birds, enemies and blocks to the game. It wasn't clear how controlling the birds should work with a mouse.

## Actions
1. Laura will develop controlling the birds.
2. Venla will create pigs and blocks and try to make the graphics show in the game.
3. Marc will draw a background for the game and work with the level loader.
4. Roope will work with the level loader.
> The next meeting is held on Monday 22.11.2021 14::00

## Project status:
We have a basic structure for many parts of the game, some graphics and a simple program using Box2D physics.

### TODOs
1. No additional TODOs.


# Meeting 22.11.2021 14::00

**Participants**:
1. Marc
2. Roope
3. Laura
4. Venla

## Summary of works
1. Roope had started implementing a game logic system to keep track of the birds etc.
2. Venla implemented 2 new classes in addition to Bird: Pig and Box (Enemies and obstacles). She also made the actual textures
of these classes to be painted on the screen.
3. Marc produced a system for loading the levels from text files. He also drew a backround for the game level.
4. Laura had made it possible to select a bird by clicking it with a mouse. Also each Bird can only be thrown once.

## Challenges
1. The Pig hitbox has a bug: sometimes dies before the bird hits.
2. The Qt textures rotate around the top left corner, whereas the 
box2d objects around their center.

## Actions
1. Laura will finish the slingshot: velocity and angle can be adjusted with the mouse.
2. Venla is going to implement a bird with a speed boost. She'll also 
look into the graphics bugs.
3. Marc will merge the level loading system to the existing game.
4. Roope is going to finish the game logic system. Also, to make 
the pig die only from a reasonably high impulse.
> Exceptionally, the next meeting shall be held at wednesday 1.12 14.00 due to many of us being detained at monday.

## Project status:
Most of the core components of the game have been created. However, some parts are lacking and our work must be merged together.

### TODOs
1. the screen should be moved so that the origin and the slingshot
are at the bottom left corner.


# Meeting 01.12.2021 14::15

**Participants**:
1. Marc
2. Roope
3. Laura
4. Venla

## Summary of works:
1. Roope had worked on the game logic and implemented a contact listener for collisions between objects.
2. Venla had implemented and done graphics for rock class and implemented speed boost for the bird. Also the angle bug was fixed.
3. Marc had done a very impressive level menu and finished the background.
4. Laura had implemented the slingshot property for the birds.

## Challenges
1. How to merge everything.
2. How to make the view follow bird sideways.
3. Marc's level menu crashes if you exit the level.

## Actions
1. The group decided to meet on Friday to merge and not do anything new before that.

## Project status:
Once everything is merged, we are at an okay place. There is still a lot to do but we are confident we will get everything done.

### TODOs
1. merge
2. make view follow bird

> The next (merge)meeting will be held on Friday 3.12.2021


# Meeting 06.12.2021 14::00

**Participants**:
1. Marc
2. Roope
3. Laura
4. Venla

## Summary of works:
1. We had a merge meeting last Friday (3.12.), where we merged three branches together to get all the features we had that far to one branch.
2. Marc had implemented graphics for the ground.
3. Roope fixed the problem with the change of coordinate system during the weekend.

## Challenges
1. We are unsure how to make the scene follow the flying bird.
2. Venla and Laura had some issues trying to run the new merged branch.
3. In general, we still have a lot of small things to do.

## Actions
1. Marc will implement destructors and scan for memory leaks. He will also make some levels and allow level loading from text files.
2. Roope will try to make compiling the code faster and write installation instructions. He will also make sure that the game world is printed at the correct position and that the scene follows the flying bird.
3. Laura and Venla will write a first draft of the documentation. They will also make birds selectable so that the next bird moves to the slingshot when the previous bird is shot and make the obstacles destroyable.

## Project status:
We now have everything important in one branch, and a lot of the basic properties of the game are working.

### TODOs
1. Finish the project during this week. No additional TODOs before the next meeting.

> The next meeting will be held on Wednesday 8.12.2021 13::00, after which we will have a meeting with the teaching assistant at 14::00.
