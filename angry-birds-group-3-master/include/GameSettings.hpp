#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP


/**
 * @brief Class with functions to convert box2d coordinates to scene coordinates
 *        and vice versa.
 * 
 */
class GameSettings
{
    public:
        static constexpr float m2pixels = 25;

        // input: left corner of the object in box2d coordinates
        // returns: top left corner of the object Qt coordinates
        static float Box2DToQtX(float x) { return x*m2pixels + 640; }
        static float Box2DToQtY(float y) { return y*m2pixels*(-1) + 360; }

        // input: left corner of the object in Qt coordinates
        // returns: top left corner of the object box2d coordinates
        static float QtToBox2DX(float x) { return (x - 640)/m2pixels; }
        static float QtToBox2DY(float y) { return (y - 360)/m2pixels*(-1); }
};


#endif