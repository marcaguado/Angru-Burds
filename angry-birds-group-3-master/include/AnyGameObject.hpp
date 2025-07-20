#ifndef ANYGAMEOBJECT_HPP
#define ANYGAMEOBJECT_HPP

#include <string>


/**
 * @brief A class name carrier for MyContactListener
 * 
 */
class AnyGameObject {
    public:
        AnyGameObject() {
            className = "AnyGameObject";
        }
        ~AnyGameObject() {}


        std::string className = "AnyGameObject";
};

#endif