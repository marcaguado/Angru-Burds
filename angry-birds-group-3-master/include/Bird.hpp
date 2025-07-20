#ifndef BIRD_HPP
#define BIRD_HPP

#include <sstream>
#include <iostream>

#include <QGraphicsRectItem>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QThread>

#include <b2_polygon_shape.h>
#include <b2_fixture.h>
#include <b2_body.h>

#include "GameSettings.hpp"
#include "PhysObject.hpp"

class GameCore;

/**
 * @brief Bird, which extends as a physical object. Can be
 *        shot with the mouse. 
 * 
 */
class Bird : public PhysObject {
    public:
        // Constructor
        Bird(GameCore& core, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
         ~Bird() {}
        
        
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }

        // Graphical representation
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
            QRectF target(0,0,w * m2pixels, h * m2pixels);
            QImage image("graphics/pinkbird.png");
            painter->drawImage(target,image);
        }

        // Update birds coordinates
        void Update();
      
        // Virtual function of QGraphicsItem for accepting mouse commands
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

        // Shoots the Bird. 
        // Also marks isShot = true. This causes the bird to be deleted when it returns to rest, 
        // due to the functionality in Update();
        void Shoot(QGraphicsSceneMouseEvent *event);
        // Returns whether the bird is shot or not
        bool isShot() const;
    
    private:
        GameCore& core;
        bool isSelected = false;
        bool shot = false;
        bool countAndDelete = false;
        int counter = 0;
};

/**
 * @brief A special bird that inherits Bird. Has speed boost.
 * 
 */
class BlueBird : public Bird {
    public:
        // Constructor
        BlueBird(GameCore& core, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~BlueBird() {}  
        // Virtual function of QGraphicsItem for accepting mouse commands
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
        // Speed boost
        void specialShoot();
        // Graphical representation
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
        QRectF target(0,0,w * m2pixels, h * m2pixels);
        QImage image("graphics/bluebird.png");
        painter->drawImage(target,image);

        }
        
    private:
    bool specialShot_;
};

#endif
