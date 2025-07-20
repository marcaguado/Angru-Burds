#include "Pig.hpp"
#include "GameCore.hpp"


/**
 * @brief Construct a new Pig:: Pig object
 * 
 * @param core_ GameCore where the pig lives
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
Pig::Pig(GameCore& core_, float x0, float y0, float a0) 
: PhysObject(*core_.world, x0, y0, a0), core(core_)
{
    className = "Pig";

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
 * @brief Update pig's position from box2d coordinates to scene coordinates
 * 
 */
void Pig::Update() {
   PhysObject::Update();
}

/**
 * @brief The pig is deleted from the game if kinetic energy of the pig or 
 *        the colliding object is large enough.
 * 
 * @param ob Colliding object
 */
void Pig::Collision(PhysObject* ob) {
    // Calculating velocity and mass of both objects
    b2Vec2 v_ob = ob->body->GetLinearVelocity();
    b2Vec2 v_this = body->GetLinearVelocity();
    b2Vec2 v_diff = (v_ob - v_this);
    float speedSquared = (v_ob - v_this).LengthSquared();
    float m_ob = ob->body->GetMass();
    float m_this = body->GetMass();

    
    // If the kinetic energy is large enough, pig is deleted.
    float kenergy_this = m_this*(v_this.LengthSquared())/2;
    float kenergy_ob = m_ob*(v_ob.LengthSquared())/2;
    
    if(kenergy_ob > 60 || kenergy_this > 60) {
        deleteThis = true;
    }
    std::cout << kenergy_ob << std::endl;

}

    
