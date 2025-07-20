#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

#include "GameCore.hpp"
#include "Pig.hpp"
#include "GraphicsTester.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QGraphicsScene scene(0, 0,1280,720);
    QGraphicsView view(&scene);
    view.setScene(&scene);
    view.show();
    QTimer levelExit;

    GameCore core(scene, view);

    GraphicsTester tester(core);

    QTimer::singleShot(0, &tester, SLOT(Test()));
    
    //Start the GUI.
    return a.exec();
}
