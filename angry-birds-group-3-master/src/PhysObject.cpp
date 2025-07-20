#include "PhysObject.hpp"



/**
 * @brief Construct a new Phys Object:: Phys Object object
 * 
 * @param world_ Box2d world where object is placed
 * @param x0 x-coordinate
 * @param y0 y-coordinate
 * @param a0 angle
 */
PhysObject::PhysObject(b2World& world_, float x0, float y0, float a0) 
: AnyGameObject(), world(world_)
{
    // Creating a dynamic 'body' at (x0, y0).
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x0, y0);
    bodyDef.angle = a0;
    body = world.CreateBody(&bodyDef);
}
/**
 * @brief Destroy the Phys Object:: Phys Object object
 *        The box2d body is deleted from the world.
 * 
 */
PhysObject::~PhysObject() {
    if(body) world.DestroyBody(body);
}

/**
 * @brief Converts the box2d position (meters) to Qt scene coordinates (pixels)
 * 
 */
void PhysObject::Update() {
    // Converting the box2d position: center point in meters (positive y axis up)
    // into the Qt position: top left corner in pixels (negative y axis up)
    
    float x_topLeft = body->GetPosition().x - (w / 2);
    float y_topLeft = body->GetPosition().y + (h / 2);

    float x_Qt = GameSettings::Box2DToQtX(x_topLeft);
    float y_Qt = GameSettings::Box2DToQtY(y_topLeft);

    float angle_Qt = body->GetAngle() * (180 / 3.14) * (-1);
    

    // Setting the new Qt position. 
    setTransformOriginPoint(boundingRect().center());
    setPos(x_Qt, y_Qt);
    setRotation(angle_Qt);
}

