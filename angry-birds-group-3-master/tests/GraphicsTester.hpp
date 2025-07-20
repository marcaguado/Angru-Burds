#include <QObject>

#include "GameCore.hpp"
#include "Pig.hpp"
#include "Box.hpp"
#include "Game.hpp"

// A test class:
// Creates a game world.
// In this class you can spawn items in the world and make them do
// things in the TestLoop() function. 
// At the moment, it can drop an object against the ground in different angles,
// to see that the graphical object coincides with the physical one.
class GraphicsTester: public QObject {
    Q_OBJECT
    public:
        GraphicsTester(GameCore& core_)
        : core(core_) {}
        ~GraphicsTester();

    public slots:
        void Test();
        void Testloop();

    private:
        GameCore& core;
        QTimer timer;
        PhysObject* p1;
        int counter = 0;
        int counter1 = 0;
};