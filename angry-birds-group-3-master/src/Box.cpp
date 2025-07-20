#include "Box.hpp"
#include "GameCore.hpp"


/**
 * @brief Construct a new Box:: Box object
 * 
 * @param core_ GameCore
 * @param x0 x-coordinate 
 * @param y0 y-coordinate
 * @param a0 angle
 */
Box::Box(GameCore& core_, float x0, float y0, float a0) 
: PhysObject(*core_.world, x0, y0, a0), core(core_)
{
    className = "Box";
    // Creating a box fixture for the 'body'.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w/2, h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    body->GetUserData().pointer = (uintptr_t)this;

    Update();
}

/**
 * @brief The box is deleted from the game if kinetic energy of the colliding bird
 *        is large enough
 * 
 * @param ob Colliding object
 */
void Box::Collision(PhysObject* ob) {
    // Calculating velocity and mass of bird
    b2Vec2 v_ob = ob->body->GetLinearVelocity();
    float m_ob = ob->body->GetMass();

    
    // If the kinetic energy of the bird is large enough, box is deleted.
    float kenergy_ob = m_ob*(v_ob.LengthSquared())/2;
    
    if(kenergy_ob > 150) {
        deleteThis = true;
    }
}


/**
 * @brief Construct a new Box Type 2:: Box Type 2 object (Wooden Pillar)
 * 
 * @param core_ GameCore
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
BoxType2::BoxType2 (GameCore& core_, float x0, float y0, float a0) 
: PhysObject(*core_.world, x0, y0, a0), core(core_) {
    className = "BoxType2";
    // Creating a box fixture for the 'body'.
    w = 8;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w/2, h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    body->GetUserData().pointer = (uintptr_t)this;

    Update();
}


/**
 * @brief The pillar is deleted from the game if kinetic energy of the colliding bird
 *        is large enough
 * 
 * @param ob Colliding object
 */
void BoxType2::Collision(PhysObject* ob) {
    // Calculating velocity and mass of bird
    b2Vec2 v_ob = ob->body->GetLinearVelocity();
    float m_ob = ob->body->GetMass();

    
    // If the kinetic energy of the bird is large enough, box is deleted.
    float kenergy_ob = m_ob*(v_ob.LengthSquared())/2;
    
    if(kenergy_ob > 200) {
        deleteThis = true;
    }
}

BoxType3::BoxType3 (GameCore& core_, float x0, float y0, float a0) 
: PhysObject(*core_.world, x0, y0, a0), core(core_) {
    className = "BoxType3";
    // Creating a box fixture for the 'body'.
    w = 4;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w/2, h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    body->GetUserData().pointer = (uintptr_t)this;

    Update();
}

void BoxType3::Collision(PhysObject* ob) {
    // Calculating velocity and mass of bird
    b2Vec2 v_ob = ob->body->GetLinearVelocity();
    float m_ob = ob->body->GetMass();
    
    // If the kinetic energy of the bird is large enough, box is deleted.
    float kenergy_ob = m_ob*(v_ob.LengthSquared())/2;
    
    if(kenergy_ob > 200) {
        deleteThis = true;
    }
}

/**
 * @brief Construct a new Rock:: Rock object
 * 
 * @param core_ GameCore
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
Rock::Rock(b2World& world, float x0, float y0, float a0) 
: PhysObject(world, x0, y0, a0)
{
    className = "Rock";
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w/2, h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    // rock is double the density of a box
    fixtureDef.density = 2.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    body->GetUserData().pointer = (uintptr_t)this;

    Update(); 
}

/**
 * @brief Construct a new Rock Type 2:: Rock Type 2 object
 * 
 * @param core_ GameCore
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
RockType2::RockType2(b2World& world, float x0, float y0, float a0) 
: PhysObject(world, x0, y0, a0)
{
    className = "Rock";
    b2PolygonShape dynamicBox;
    w = 8;
    dynamicBox.SetAsBox(w/2, h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    // rock is double the density of a box
    fixtureDef.density = 2.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    body->GetUserData().pointer = (uintptr_t)this;

    Update(); 
}

