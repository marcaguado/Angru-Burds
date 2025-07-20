#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsTextItem>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "ButtonPlay.hpp"
#include "ButtonExit.hpp"
#include "ButtonLevel.hpp"
#include "LevelLoader.hpp"

/**
 * @brief A game object that extends as a QGraphicsView. Determined what is 
 *        shown to the user: menu, level selector or a level.
 * 
 */
class Game: public QGraphicsView{
    Q_OBJECT
    public:
        // Constructor
        Game(QWidget* parent=NULL);
        // Destructor
        ~Game() {}
        // Scene
        QGraphicsScene* scene;
        
    public slots:
        void displayMainMenu();
        void displayLevelSelector();
        void startLevelSlot1();
        void startLevelSlot2();
        void startLevelSlot3();
    
    private:
        LevelLoader level;
};

#endif 