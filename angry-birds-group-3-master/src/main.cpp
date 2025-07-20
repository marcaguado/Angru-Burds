#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <b2_world.h>
#include <b2_math.h>
#include <b2_body.h>
#include <b2_polygon_shape.h>
#include <b2_fixture.h>

#include "LevelLoader.hpp"
#include "GameCore.hpp"
#include "LevelGround.hpp"
#include "PhysObject.hpp"
#include "Game.hpp"




int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    // Creates a new game
    Game game;
    game.show();
    game.displayMainMenu(); // --> Launches the Main Menu 

    //Start the GUI.
    return a.exec();
}
