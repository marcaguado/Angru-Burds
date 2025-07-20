#ifndef PIG_HPP
#define PIG_HPP

#include <QGraphicsRectItem>
#include <QPainter>
#include <QKeyEvent>

#include <b2_polygon_shape.h>
#include <b2_fixture.h>

#include <iostream>

#include "PhysObject.hpp"
#include "Bird.hpp"


class GameCore;

/**
 * @brief Enemy of the game. A pig has a dynamic body
 *        and it can be killed in a collision. 
 * 
 */
class Pig : public PhysObject {

    public:
        // Constructor
        Pig(GameCore& core, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~Pig() {}
        
    
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }

        // Graphical representation
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
            QRectF target(0,0,w * m2pixels, h * m2pixels);
            QImage image("graphics/pig.png");
            painter->drawImage(target,image);
        }

        // Updates coordinates from box2D world to scene
        void Update() override;

        // Is run when something collides with pig
        void Collision(PhysObject* ob) override;

    private:
        // Reference to GameCore that stores the pig
        GameCore& core;
       
};

#endif