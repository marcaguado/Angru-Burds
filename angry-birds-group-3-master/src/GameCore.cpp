#include "GameCore.hpp"
#include "Game.hpp"


/**
 * @brief Construct a new Game Core:: Game Core object.
 *        Sets the scene and game according to given parameters.
 *        Initializes the world and ground as null pointers, as they are created in Load() function.
 *        Creates a new timer that is connected to GameLoop() function.
 *
 * @param scene_ Scene created in Game
 * @param game_ Game
 */
GameCore::GameCore(Game& game_)
: scene(game_.scene), timer(this), view((QGraphicsView* )&game_), game(&game_),
world(nullptr), ground(nullptr)
{
    //timer = new QTimer(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(GameLoop()));
}

GameCore::GameCore(QGraphicsScene& scene_, QGraphicsView& view_)
: scene(&scene_), timer(this), view(&view_), game(nullptr),
world(nullptr), ground(nullptr)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(GameLoop()));
}

/**
 * @brief Destroy the Game Core:: Game Core object
 * 
 */
GameCore::~GameCore() {
    ClearMap();

    // Deleting timer
    //delete timer;
 }

/**
 * @brief Initialize the game core by creating a world and level ground. Set map as active.
 * 
 */
 void GameCore::Load() {
     // a box2d world for physics simulation.
    b2Vec2 gravity(0.0f, -10.0f);
   
    world = new b2World(gravity);
    world->SetContactListener(&listener);

    // a ground box for the world
    ground = new LevelGround(*world);

    // a small box: the top left corner of which indicates the origin
    QGraphicsRectItem* origin = new QGraphicsRectItem;
    origin->setRect(640, 360, GameSettings::m2pixels, GameSettings::m2pixels);

    scene->addItem(ground);
    //scene->addItem(origin);

    mapActive = true;
    score = 0;
 }

  /**
 * @brief Displays level data: how many items left
 * 
 */
void GameCore::DisplayText() {

    // Delete old texts
    for(QGraphicsTextItem* t : texts) {
        scene->removeItem(t);
        delete t;
    }
    texts.clear();

    // QString requires this step
    int a = birds.size();
    int b = pigs.size();
    int c = obstacles.size();


    QFont serifFont("Times", 15, QFont::Bold);

    QString birds = "Birds in level: " + QString::number(a);
    QGraphicsTextItem* text1 = scene->addText(birds);
    text1->setPos(200, 180);
    text1->setFont(serifFont);


    QString enemies = "Enemies in level: " + QString::number(b);
    QGraphicsTextItem* text2 = scene->addText(enemies);
    text2->setPos(200, 200);
    text2->setFont(serifFont);

    QString objects = "Objects in level: " + QString::number(c);
    QGraphicsTextItem* text3 = scene->addText(objects);
    text3->setPos(200,220);
    text3->setFont(serifFont);

    // Add texts to private vector
    texts.push_back(text1);
    texts.push_back(text2);
    texts.push_back(text3);
}

/**
 * @brief Focus the game on given object
 * 
 * @param p PhysObject to focus on
 */
void GameCore::Focus(PhysObject* p) {
    
    view->centerOn(p);
}

/**
 * @brief Adds a bird to scene
 * 
 * @param b Bird to be added
 */
void GameCore::AddBird(Bird* b) {
    birds.push_back(b);
    scene->addItem(b);
}

/**
 * @brief Adds a pig to scene
 * 
 * @param p Pig to be added
 */
void GameCore::AddPig(Pig* p) {
    pigs.push_back(p);
    scene->addItem(p);
}

/**
 * @brief Adds an obstacle to scene
 * 
 * @param ob Obstacle to be added
 */
void GameCore::AddObstacle(PhysObject* ob) {
    obstacles.push_back(ob);
    scene->addItem(ob);
}

/**
 * @brief Delete bird from scene.
 *        Ends the game if there are no birds left.
 * 
 * @param b Bird to be deleted
 */
void GameCore::DeleteBird(Bird* b) {

    auto xpos = b->x();

    std::vector<Bird*>::iterator position = std::find(birds.begin(), birds.end(), b);
    if (position != birds.end()) { // == myVector.end() means the element was not found
        scene->removeItem(*position);
        birds.erase(position);
        delete b;
    }

    if (birds.empty()) {
         auto xpos = 600;

        // if level has not been won yet
        if(!pigs.empty()) {
            // make view go back to 600,200
            view->ensureVisible(xpos,200,1,1,400,20);
            // Add text to screen
            QGraphicsTextItem* text = new QGraphicsTextItem(QString("Out of birds. You lost."));
            text->setPos(xpos,150);
            QFont serifFont("Times", 15, QFont::Bold);
            QFont serifFont2("Times", 20, QFont::Bold);
            text->setFont(serifFont);
            scene->addItem(text);
            
            // Score
            QString currentscore = "Score: " + QString::number(score);
            QGraphicsTextItem* text4 = scene->addText(currentscore);
            text4->setPos(xpos+30,180);
            text4->setFont(serifFont2);

            if(score > 50) {
            // Display 2 stars
            QImage image("graphics/TwoStars.png");
            QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            item->setPos(xpos+20, 220);
            scene->addItem(item);
            } else if(score!=0) {
            // Display 1 star
            QImage image("graphics/OneStars.png");
            QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            item->setPos(xpos+20, 220);
            scene->addItem(item);

            }
        }
        
        // Start count down to exiting
        // countAndExit = true;
    } else {
        // Focus on the next bird and make it jump a little to indicate it is now shootable
        Focus((*birds.begin()));
        b2Vec2 v(0, 4);
        (*birds.begin())->body->SetLinearVelocity(v);
        (*birds.begin())->setFlag(QGraphicsItem::ItemIsSelectable);  
    }
    // Update text
    DisplayText();
}

/**
 * @brief Delete a pig from scene.
 *        Stops the game if all pigs are destroyed.
 * 
 * @param p Pig to be deleted
 */
void GameCore::DeletePig(Pig* p) {

    score += 50;

    auto xpos = p->x();
    
    std::vector<Pig*>::iterator position = std::find(pigs.begin(), pigs.end(), p);
    if (position != pigs.end()) {
        scene->removeItem(*position);
        pigs.erase(position);
        delete p;
        
    }
    
    if (pigs.empty()) {
        // remaining birds add to score
        for(auto b : birds) {
            score += 100;
        }
        // Add text to screen
        QGraphicsTextItem* text = new QGraphicsTextItem(QString("All pigs eliminated. You won!"));
        text->setPos(xpos,150);
        QFont serifFont("Times", 15, QFont::Bold);
        QFont serifFont2("Times", 20, QFont::Bold);
        text->setFont(serifFont);
        scene->addItem(text);

        // Score
        QString currentscore = "Score: " + QString::number(score);
        QGraphicsTextItem* text4 = scene->addText(currentscore);
        text4->setPos(xpos+50,180);
        text4->setFont(serifFont2);

        // Add three stars
        QImage image("graphics/ThreeStars.png");
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        item->setPos(xpos+40, 220);
        scene->addItem(item);
        
        // Start count down to exit
        // countAndExit = true;
    }
     // Update text
    DisplayText();
}

/**
 * @brief Delete a box from scene
 * 
 * @param p Box to be deleted
 */
void GameCore::DeleteBox(PhysObject* p) {
    
    std::vector<PhysObject*>::iterator position = std::find(obstacles.begin(), obstacles.end(), p);
    if (position != obstacles.end()) { // == myVector.end() means the element was not found
    scene->removeItem(p);
    obstacles.erase(position);
    delete p;
    }
    score += 10;
    // Update text
    DisplayText();
}

/**
 * @brief Start level timer
 * 
 */
void GameCore::StartTimer() {
    std::cout << "Level timer started." << std::endl;

    timer.start(timestep*1e3);
}

/**
 * @brief If the map is active, it is set as nonactive and 
 *        exited by starting exitLevel timer. 
 *        The level timer is stopped and map is cleared.
 *        If map is nonactive, nothing happens.
 * 
 */
void GameCore::ExitMap() {
    if (!mapActive) return;
    else mapActive = false;

    countAndExit = false;

    //exitLevel.start();
    timer.stop();
    std::cout << "Level timer stopped." << std::endl;
    ClearMap();
    // if (game != nullptr) game->displayMainMenu();
}

/**
 * @brief Simulates physics of the world every 1/60 seconds
 *        and updates the object positions. If the exit count down
 *        has been started, the level is exited after 3 seconds.
 * 
 */
void GameCore::GameLoop() {
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Simulating the box2d world for one 'timestep'.
    world->Step(timestep, velocityIterations, positionIterations);
    
    // Updating objects.
    for (auto b : birds) {
        b->Update();
        if(b->deleteThis) DeleteBird((Bird*)b);
    }
    for (auto p : pigs) {
        p->Update();
        if(p->deleteThis) DeletePig((Pig*)p);
    }
    for (auto ob : obstacles) {
        ob->Update();
        if(ob->deleteThis) DeleteBox(ob);
    }

    if (countAndExit) {
        if (counter < 180) {
            counter++;
        } else {
            counter = 0;
            ExitMap();
        }
    }
}

/**
 * @brief Clears the map from objects and deletes them.
 *        Deletes level ground and box2d world.
 * 
 */
void GameCore::ClearMap() {
    // Clearing containers
    for(auto b : birds) {
        delete b;
    }
    birds.clear();

    for(auto p : pigs) {
        delete p;
    }
    pigs.clear();

    for(auto o : obstacles) {
        delete o;
    }
    obstacles.clear();

    for( auto t : texts) {
        delete t;
    }
    texts.clear();

    // Deleting ground and world
    if (ground != nullptr) {
        delete ground;
        ground = nullptr;
    }
    if (world != nullptr) {
        delete world;
        world = nullptr;
    }
}
