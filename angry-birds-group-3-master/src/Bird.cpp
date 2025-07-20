#include "Bird.hpp"
#include "GameCore.hpp"

/**
 * @brief Construct a new Bird:: Bird object
 * 
 * @param core_ GameCore
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
Bird::Bird(GameCore& core_, float x0, float y0, float a0) 
: PhysObject(*core_.world, x0, y0, a0), core(core_)
{
    className = "Bird";
    

    // Creating a box fixture for the 'body'.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w/2, h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    body->GetUserData().pointer = (uintptr_t)this;

    // Make bird accept mouse commands once it is made selectable
    this->setAcceptedMouseButtons(Qt::LeftButton);


    Update();
}


/**
 * @brief Updates the bird's coordinates and deletes it after 1.5 seconds after it
 *        has hit the ground.
 */
void Bird::Update() {
   
   PhysObject::Update();

    // The bird is deleted after being shot and remaining in rest for 1.5 seconds.
    if (isShot()) {
        // Center the view on this bird after it is shot
        core.Focus((PhysObject*)this);
        float speed = body->GetLinearVelocity().Length();
        if(speed < 0.05) {
            countAndDelete = true;
            counter++;
        } else {
            countAndDelete = false;
        }
    }
    // If bird is out of scene, it gets deleted
    if(this->x() > 2300 || this -> x() < -10) {
        shot = false;
        countAndDelete = true;
    }
    // System for deleting the bird with a delay:
    if (countAndDelete) {
        if (counter > 3*60) deleteThis = true;
        else counter++;
    }

}
/**
 * @brief Shoots the bird to the right direction if it is not yet
 *        shot
 * 
 * @param event 
 */
void Bird::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (!shot) Shoot(event);
    
}


/**
 * @brief Gives the bird initial velocity according to the length
 *        of drag of the mouse event. Marks the bird as shot.
 * 
 * @param event Mouse event that triggered the bird
 */
void Bird::Shoot(QGraphicsSceneMouseEvent *event) {
    
    QPointF mousepos = event->lastScenePos();
    b2Vec2 bodyposition = body->GetPosition();
    b2Vec2 mousepos_in_meters(GameSettings::QtToBox2DX(mousepos.x()), GameSettings::QtToBox2DY(mousepos.y()));
    b2Vec2 difference = bodyposition - mousepos_in_meters;

    body->SetLinearVelocity(3*difference);

    shot = true;
}

/**
 * @brief Returns true if bird is shot
 * 
 * @return true if shot
 * @return false if not yet shot
 */
bool Bird::isShot() const {
    return shot;
}

/**
 * @brief Construct a new Blue Bird:: Blue Bird object
 * 
 * @param core_ GameCore
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
BlueBird::BlueBird(GameCore& core_, float x0, float y0, float a0)
    : Bird(core_, x0, y0, a0), specialShot_(false) {}

/**
 * @brief Shoots the bird if it has not yet been shot by calling Shoot().
 *        Gives speed boost if it is not yet given and bird has been shot by calling specialShoot().
 * 
 * @param event mouse event that triggered the call
 */
void BlueBird::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(!isShot()) {
        Shoot(event);
    } else {
        if(!specialShot_) specialShoot();
    }
}
/**
 * @brief Gives the bird a speed boost
 * 
 */
void BlueBird::specialShoot() {

    b2Vec2 v2 = body->GetLinearVelocity();
    b2Vec2 v(10, 10);
    body->SetLinearVelocity(v2+v2+v2+v);
    specialShot_ = true;
    

 }
