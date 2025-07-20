#include "GraphicsTester.hpp"


void GraphicsTester::Test() {
    core.Load();

    p1 = new Pig(core, 0, 0, 0);
    core.AddObstacle(p1);

    core.StartTimer();
    /*
    for (int i; i < 10; i++) {
        QThread::sleep
        p1->body->SetTransform(b2Vec2(0.0f, 0.0f), 0.0f);
    }
    */
   connect(&timer,SIGNAL(timeout()),this,SLOT(Testloop()));
   timer.start(1*1e3);
}

GraphicsTester::~GraphicsTester() {

}

void GraphicsTester::Testloop() {
    if (counter1 < 3) {
        counter1++;
        return;
    }

    if (counter == 0) {
        b2Vec2 v(0.0f, 10.0f);
        p1->body->SetLinearVelocity(v);
        const b2Vec2& test = p1->body->GetLinearVelocity();
        int k = 1;
    } else if (counter == 1) {
        p1->body->SetAngularVelocity(1.0f);
    } else if (counter == 5) counter = -1;
    
    counter++;
    std::cout << counter << std::endl;
}

