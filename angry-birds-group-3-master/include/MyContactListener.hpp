#ifndef MYCONTACTLISTENER_HPP
#define MYCONTACTLISTENER_HPP

#include <b2_world_callbacks.h>
#include <b2_contact.h>
#include <b2_collision.h>

#include <iostream>

#include "AnyGameObject.hpp"
#include "PhysObject.hpp"
#include "LevelGround.hpp"
#include "Bird.hpp"
#include "Pig.hpp"
#include "Box.hpp"

/**
 * @brief A custom b2ContactListener for the b2world.
 *        Keeps track of collisions through box2d.
 * 
 */
class MyContactListener : public b2ContactListener {
    public:
        // Runs every time that two bodies collide.
        void BeginContact(b2Contact* contact);
};

#endif