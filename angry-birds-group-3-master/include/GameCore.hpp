#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QFont>
#include <QThread>

#include <b2_world.h>
#include <b2_world_callbacks.h>
#include <b2_contact.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "GameSettings.hpp"
#include "MyContactListener.hpp"
#include "PhysObject.hpp"
#include "LevelGround.hpp"


class Game;

/**
 * @brief A GameCore object, which extends as a QObject. 
 *        Owns the objects on scene and updates their position by running
 *        the GameLoop().
 *        Takes care of game logic.
 * 
 */
class GameCore : public QObject {
    
    Q_OBJECT
    public:
        // Constructor
        GameCore(Game& game);
        GameCore(QGraphicsScene& scene, QGraphicsView& view);
        // Destructor
        ~GameCore();
        // Creates a box2D world and ground
        void Load();
        // Adds bird to scene
        void AddBird(Bird* b);
        // Adds pig to scene
        void AddPig(Pig* p);
        // Adds object to scene
        void AddObstacle(PhysObject* ob);

        // Display item data on screen
        void DisplayText();

        // Deletes the Bird 'b' from the level.
        // if all the birds run out, the level is lost and it is ended.
        void DeleteBird(Bird* b);

        // Similar to DeleteBird(), except that the level is won if the pigs run out.
        void DeletePig(Pig* p);

        // Deletes Boxes from the level
        void DeleteBox(PhysObject* p);

        // Focus the view on given object
        void Focus(PhysObject* p);
        
        //The scene that shows the level to the user.
        QGraphicsScene* scene;

        // World for the physics 
        b2World* world;


    public slots:
        //Runs the game. Triggered by 'timer' every 'timestep'.
        void GameLoop();
        // Starts the 'timer' and so the game starts running.
        void StartTimer();
        // Stops the 'timer'
        void ExitMap();

    private:
        // Clears the scene from objects and deletes them along with the ground and world.
        void ClearMap();

        bool mapActive = false;
        bool countAndExit = false;
        int counter = 0;
        int score = 0;

        QTimer timer;
        float timestep = 1.0f / 60.0f;
        MyContactListener listener;
        // The view linked to scene
        QGraphicsView* view;
        // The Game object
        Game* game;

        LevelGround* ground;
        
        // Texts to display items left
        std::vector<QGraphicsTextItem*> texts;

        // Containers that store the game objects.
        std::vector<Bird*> birds;
        std::vector<Pig*> pigs;
        std::vector<PhysObject*> obstacles;
};



#endif
