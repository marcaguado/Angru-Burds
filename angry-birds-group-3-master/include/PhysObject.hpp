#ifndef PHYSOBJECT_HPP
#define PHYSOBJECT_HPP

#include <QGraphicsItem>

#include <b2_body.h>
#include <b2_world.h>
#include <b2_polygon_shape.h>
#include <b2_fixture.h>

#include "GameSettings.hpp"
#include "AnyGameObject.hpp"

/**
 * @brief A physical object that can be placed in a Qt scene.
 *        This class extends as a QGraphicsItem but also has a physical
 *        box2d body that is placed in the box2d world.
 * 
 */
class PhysObject : public QGraphicsItem, public AnyGameObject {

    public:
        // Constructor
        PhysObject(b2World& world, float x0 = 0, float y0 = 0, float a0 = 0);
        // Destructor
        ~PhysObject();
        // Sets the Qt position of this object equal to the box2d position of the 'body'.
        void virtual Update();
        // The corresponding box2d physics object.
        b2Body* body;
        // Virtual function to take care of collisions. Empty by default.
        virtual void Collision(PhysObject* p) {}
        // determines if object should be deleted
        bool deleteThis = false;


    protected:
        // Box2D world where object's body is
        b2World& world;
        // Object dimension in meters
        float w = 2;
        float h = 2;
        // Stretch factor from box2d (meters) to Qt (pixels)
        float m2pixels = 25; 

    
};

#endif