#include "MyContactListener.hpp"

/**
 * @brief Runs when box2D detects a contact between bodies.
 *        If a contact happens between pig and something else, the pig's Collision function is called.
 *        If a bird collides with a wooden box or pillar, the box's Collision function is called.
 * 
 * @param contact Contact that triggered the function
 */
void MyContactListener::BeginContact(b2Contact* contact){

    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    uintptr_t ptrA = bodyA->GetUserData().pointer;
    uintptr_t ptrB = bodyB->GetUserData().pointer;

    PhysObject* testPA = (PhysObject*)ptrA;
    PhysObject* testPB = (PhysObject*)ptrB;
    PhysObject* theOther = NULL;
    Pig* thePig = NULL;
    PhysObject* theBox = NULL;
    Bird* theBird = NULL;

    if (testPA != NULL) {
        
        if (testPA->className == "Pig") {
            thePig = (Pig*)testPA;
            if (testPB != NULL) theOther = testPB;
        }
        else if(testPA->className == "Box" || testPA->className == "BoxType2" || testPA->className == "BoxType3") {
            theBox = (PhysObject*)testPA;
        }
        else if(testPA->className == "Bird") {
            theBird = (Bird*)testPA;
        }
       
    }

    if (testPB != NULL) {
        
        if (testPB->className == "Pig") {
            thePig = (Pig*)testPB;
            if (testPA != NULL) theOther = testPA;
        }
        else if(testPB->className == "Box" || testPB->className == "BoxType2" || testPB->className == "BoxType3") {
            theBox = (PhysObject*)testPB;
        }
        else if (testPB->className == "Bird") {
            theBird = (Bird*)testPB;
        }
        
    }

    if (theOther != NULL && thePig != NULL) {

        thePig->Collision(theOther);
    }
    if(theBox != NULL && theBird != NULL) {

        theBox->Collision(theBird);
    }
}
