#ifndef LEVELGROUND_HPP
#define LEVELGROUND_HPP

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#include <b2_body.h>
#include <b2_world.h>
#include <b2_polygon_shape.h>
#include <b2_fixture.h>

#include "GameSettings.hpp"
#include "AnyGameObject.hpp"

/**
 * @brief A static level ground object
 * 
 */
class LevelGround : public QGraphicsPixmapItem, public AnyGameObject {

    public:
        // Constructor
        LevelGround(b2World& world);
        // Destructor
        ~LevelGround();
        // Updates box2D coordinates to scene coordinates
        void virtual Update();
        // Box2D body
        b2Body* body;

    private:
        // meters to pixels stretch factor
        float m2pixels = 25;
        // width
        float w = 100;
        // heigth
        float h = 6;
        // Box2D world where ground is
        b2World& world;

};

#endif