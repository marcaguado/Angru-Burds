#ifndef LEVELLOADER_HPP
#define LEVELLOADER_HPP

#include <QGraphicsView>
#include <QGraphicsScene>

#include <fstream>

#include "GameCore.hpp"
#include "MyContactListener.hpp"
#include "Bird.hpp"
#include "Pig.hpp"
#include "Box.hpp"

class Game;

/**
 * @brief A level loading object used to load a level from file
 * 
 */
class LevelLoader {
    public: 
        // Constructor
        LevelLoader(Game& game);
        // Destructor
        ~LevelLoader() {}
        // Load the level given as parameter
        void Load(const std::string& levelName);
        // Gamecore object where objects are placed
        GameCore core;

    private:
        // Meters to pixels stretch factor
        int m2pixels = 25;  
};

#endif