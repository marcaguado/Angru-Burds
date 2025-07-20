#include "LevelLoader.hpp"


/**
 * @brief Construct a new Level Loader:: Level Loader object
 *        Initializes a game core with given scene and game objects.
 * 
 * @param scene Scene created by game
 * @param game Game that created this object
 */
LevelLoader::LevelLoader(Game& game) 
: core(game) {}

/**
 * @brief Loads the game core with objects according to a text file.
 *        Starts the timer of the game core once loading is done.
 * 
 * @param levelName Name of the text file to be read
 */
void LevelLoader::Load(const std::string& levelName) {
    core.Load();

    // This is set here because "MyContactListener.hpp" can't be included in "GameCore.hpp"
    //core.world->SetContactListener(new MyContactListener());

    //Level Reader V2.0
    std::ifstream infile(levelName);
    if (infile.rdstate() & (infile.failbit | infile.badbit)) {
        std::cerr << "Failed to load file!" << std::endl;
    }
    else {
        std::string a;
        std::string b;
        float c;
        float d;
        float e;
        int birdcounter = 0;
        int objectcounter = 0;
        int enemycounter = 0;

        while (infile >> a >> b >> c >> d >> e) {
            if (a == "bird") {
                birdcounter++;
                if(b == "normal") {
                    Bird* bird = new Bird(core, c, d, 3.14/6);
                    if(birdcounter==1) bird->setFlag(QGraphicsItem::ItemIsSelectable);
                    core.AddBird(bird);
                }
                else if(b  == "blue") {
                    Bird* bird = new BlueBird(core, c, d, 3.14/6);
                    if(birdcounter==1) bird->setFlag(QGraphicsItem::ItemIsSelectable);
                    core.AddBird(bird);
                }
            }
            else if (a == "object") {
                objectcounter++;
                if(b == "typeA1") {
                    Box* box = new Box(core,c,d, e);
                    core.AddObstacle(box);
                }
                else if(b == "typeA2") {
                    BoxType2* box = new BoxType2(core,c,d, e);
                    core.AddObstacle(box);
                }
                else if(b == "typeA3") {
                    BoxType3* box = new BoxType3(core,c,d, e);
                    core.AddObstacle(box);
                }
                else if(b == "typeB1") {
                    Rock* testRock = new Rock(*core.world, c, d, e);
                    core.AddObstacle(testRock);
                }
                else if(b == "typeB2") {
                    RockType2* testRock = new RockType2(*core.world, c, d, e);
                    core.AddObstacle(testRock);
                }

                
            }
            else if (a == "enemy") {
                enemycounter++;
                Pig* pig = new Pig(core, c, d, 0);
                core.AddPig(pig);
            }
        }

        // Show item data on screen
        core.DisplayText();
        // Start the level:
        QTimer::singleShot(1000, &core, SLOT(StartTimer()));
    }
}
