#include "Game.hpp"

/**
 * @brief Construct a new Game:: Game object
 * 
 * @param parent QWidget parent
 */
Game::Game(QWidget *parent)
: scene(new QGraphicsScene(0, 0, 2280, 720)), level(*this) {
    
    // Screen Settings
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    // Scene Creation & Settings
    scene->setSceneRect(0, 0,1280,720);
    setScene(scene);
}

/**
 * @brief Display the main menu with play button.
 * 
 */
void Game::displayMainMenu(){

    // Clear Previous Scene
    scene->clear();
    scene->setSceneRect(0, 0,1280,720);

    // Set Background Image
    QPixmap pixmap("graphics/BackgroundTitle.png");
    scene->setBackgroundBrush(pixmap);

    // Create The Play Button
    ButtonPlay* playButton = new ButtonPlay();
    int buttonPosX = this->width()/2 - playButton->boundingRect().width()/2;
    int buttonPosY = 275;
    playButton->setPos(buttonPosX,buttonPosY);
    connect(playButton,SIGNAL(clicked()),this,SLOT(displayLevelSelector())); // --> To Level Selector Scene
    scene->addItem(playButton);

    // Create The Exit Button
    ButtonExit* exitButton = new ButtonExit();
    int exitButtonPosX = 10;
    int exitButtonPosY = 20;
    exitButton->setPos(exitButtonPosX,exitButtonPosY);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close())); // --> Closes The Game
    scene->addItem(exitButton);

}

/**
 * @brief Display the level selector view and stop the level timer.
 * 
 */
void Game::displayLevelSelector() {

    // Clear Previous Scene
    scene->clear();
    scene->setSceneRect(0, 0,1280,720);

    // Set Background Image
    QPixmap pixmap("graphics/BackgroundSelector.png");
    scene->setBackgroundBrush(pixmap);

    // Create The Return To Menu Button
    ButtonExit* exitButton = new ButtonExit();
    int exitButtonPosX = 10;
    int exitButtonPosY = 20;
    exitButton->setPos(exitButtonPosX,exitButtonPosY);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(displayMainMenu())); // --> To Main Menu
    scene->addItem(exitButton);

    // Create The Level 1 Button
    ButtonLevel* level1Button = new ButtonLevel(1);
    int level1ButtonPosX = 133;
    int level1ButtonPosY = 200;
    level1Button->setPos(level1ButtonPosX,level1ButtonPosY);
    connect(level1Button,SIGNAL(clicked()),this,SLOT(startLevelSlot1())); // --> To Level 1
    scene->addItem(level1Button);

    // Create The Level 2 Button
    ButtonLevel* level2Button = new ButtonLevel(2);
    int level2ButtonPosX = 515;
    int level2ButtonPosY = 200;
    level2Button->setPos(level2ButtonPosX, level2ButtonPosY);
    connect(level2Button,SIGNAL(clicked()),this,SLOT(startLevelSlot2())); // --> To Level 2
    scene->addItem(level2Button);

    // Create The Level 3 Button
    ButtonLevel* level3Button = new ButtonLevel(3);
    int level3ButtonPosX = 897;
    int level3ButtonPosY = 200;
    level3Button->setPos(level3ButtonPosX, level3ButtonPosY);
    connect(level3Button,SIGNAL(clicked()),this,SLOT(startLevelSlot3())); // --> To Level 3
    scene->addItem(level3Button);

}

/**
 * @brief Start level 1
 * 
 */
void Game::startLevelSlot1(){
    // Clear Previous Scene
    scene->clear();
    scene->setSceneRect(0, 0,2280,720);

    // Set Background Image
    QPixmap pixmap("graphics/BackgroundWorld.png");
    scene->setBackgroundBrush(pixmap);

    // Create The Return To Menu Button
    ButtonExit* exitButton = new ButtonExit();
    int exitButtonPosX = 10;
    int exitButtonPosY = 20;
    exitButton->setPos(exitButtonPosX,exitButtonPosY);
    connect(exitButton,SIGNAL(clicked()),&level.core,SLOT(ExitMap())); // --> To Main Menu
    connect(exitButton,SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(exitButton);

    // Loads The Level
    level.Load("levels/level1.txt");

}

/**
 * @brief Start level 2
 * 
 */
void Game::startLevelSlot2(){
    // Clear Previous Scene
    scene->clear();
    scene->setSceneRect(0, 0, 2280, 720);

    // Set Background Image
    QPixmap pixmap("graphics/BackgroundWorld.png");
    scene->setBackgroundBrush(pixmap);

    // Create The Return To Menu Button
    ButtonExit* exitButton = new ButtonExit();
    int exitButtonPosX = 10;
    int exitButtonPosY = 20;
    exitButton->setPos(exitButtonPosX,exitButtonPosY);   
    connect(exitButton,SIGNAL(clicked()),&level.core,SLOT(ExitMap()));
    connect(exitButton,SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(exitButton);

    // Loads The Level
    level.Load("levels/level2.txt"); 
}

/**
 * @brief Start level 3
 * 
 */
void Game::startLevelSlot3(){
    // Clear Previous Scene
    scene->clear();
    scene->setSceneRect(0, 0, 2280, 720);

    // Set Background Image
    QPixmap pixmap("graphics/BackgroundWorld.png");
    scene->setBackgroundBrush(pixmap);

    // Create The Return To Menu Button
    ButtonExit* exitButton = new ButtonExit();
    int exitButtonPosX = 10;
    int exitButtonPosY = 20;
    exitButton->setPos(exitButtonPosX,exitButtonPosY);
    connect(exitButton,SIGNAL(clicked()),&level.core,SLOT(ExitMap()));
    connect(exitButton,SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(exitButton);

    // Loads The Level
    level.Load("levels/level3.txt");

}


