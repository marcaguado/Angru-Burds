#include "LevelGround.hpp"


/**
 * @brief Construct a new Level Ground:: Level Ground object
 * 
 * @param world Box2d world where ground is constructed
 */
LevelGround::LevelGround(b2World& world)
: world(world) {
    className = "LevelGround";

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(24.0f, -10.5f);
    body = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(w, h/2);

    body->CreateFixture(&groundBox, 100.0f);

    body->GetUserData().pointer = (uintptr_t)this;
    
    setPixmap(QPixmap("graphics/longground.png"));

    Update();
}

/**
 * @brief Destroy the Level Ground:: Level Ground object
 * 
 */
LevelGround::~LevelGround() {
    if(body) world.DestroyBody(body);
}

/**
 * @brief Update ground's position on screen from its box2d coordinates
 * 
 */
void LevelGround::Update() {
    float x_topLeft = body->GetPosition().x - (w / 2);
    float y_topLeft = body->GetPosition().y + (h / 2);

    float x_Qt = GameSettings::Box2DToQtX(x_topLeft);
    float y_Qt = GameSettings::Box2DToQtY(y_topLeft);

    setPos(x_Qt, y_Qt);
}