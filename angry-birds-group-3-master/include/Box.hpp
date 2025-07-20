#ifndef BOX_HPP
#define BOX_HPP

#include <QGraphicsRectItem>
#include <QPainter>
#include <QKeyEvent>

#include <b2_polygon_shape.h>
#include <b2_fixture.h>

#include "PhysObject.hpp"


class GameCore;

/**
 * @brief A wooden box. Can be destroyed with a bird.
 * 
 */
class Box : public PhysObject {
    public:
        // Constructor
        Box(GameCore& core_, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~Box() {}
     
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }
        // Graphical representation
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
            QRectF target(0,0,w * m2pixels, h * m2pixels);
            QImage image("graphics/box.png");
            painter->drawImage(target,image);
        }
        // Runs when a Bird hits the Box
        void Collision(PhysObject* ob) override;
        
    private:
        GameCore& core;
            
};                      


/**
 * @brief A wooden pillar
 * 
 */
class BoxType2 : public PhysObject {
    public:
        // Constructor
        BoxType2(GameCore& core_, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~BoxType2() {}
        
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }
        // Graphical representation
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
       
            QRectF target(0,0, w * m2pixels, h * m2pixels);
            QImage image("graphics/pillar.png");
            painter->drawImage(target,image);
        }

        // Runs when a Bird hits the Box
        void Collision(PhysObject* ob) override;
       
        private:
        GameCore& core;

    
};

class BoxType3 : public PhysObject {
    public:
        BoxType3(GameCore& core_, float x0 = 0, float y0 = 0, float a0 = 0);
        ~BoxType3() {}
        // 2 Virtual functions of QGraphicsItem implemented:
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {

            QRectF target(0,0, w * m2pixels, h * m2pixels);
            QImage image("graphics/DoubleBox.png");
            painter->drawImage(target,image);
        }

        // Runs when a Bird hits the Box
        void Collision(PhysObject* ob) override;
        // Virtual function to take care of deleting the box

        private:
        GameCore& core;
};

/**
 * @brief A rock object. Cannot be destroyed.
 * 
 */
class Rock : public PhysObject {

    public:
        // Constructor
        Rock(b2World& world, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~Rock() {}
        
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }
        // Graphical representation
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
            QRectF target(0,0,w * m2pixels, h * m2pixels);
            QImage image("graphics/rock.png");
            painter->drawImage(target,image);
        }
};

/**
 * @brief A rock pillar. Cannot be destroyed.
 * 
 */
class RockType2 : public PhysObject {

    public:
        // Constructor
        RockType2(b2World& world, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~RockType2() {}
       
        QRectF boundingRect() const override {
            return QRectF(0,0, w * m2pixels, h * m2pixels);
        }
        // Graphical representation
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
            
            QRectF target(0,0,w * m2pixels, h * m2pixels);
            QImage image("graphics/stonepillar.png");
            painter->drawImage(target,image);
            
        }

};

#endif