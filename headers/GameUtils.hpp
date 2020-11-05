#include <SFML/Graphics.hpp>

namespace GameUtils {
    float lerp1d(float a, float b, float k)
    {
        return (1 - k) * a + k * b;
    }

    sf::Vector2f lerp2d(sf::Vector2f a, sf::Vector2f b, float k)
    {
        return sf::Vector2f(lerp1d(a.x, b.x, k), lerp1d(a.y, b.y, k));
    }

    sf::Vector2f scalare(sf::Vector2f v, float s) // v * s
    {
        v.x *= s;
        v.y *= s;
        return v;
    }

    bool discordi(float a, float b)
    {
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
            return true;
        return false;
    }

    //controllo collisioni
    bool colliding(sf::Vector2f rect1_pos, sf::Vector2f rect1_size, sf::Vector2f rect2_pos, sf::Vector2f rect2_size)
    {
        if (rect1_pos.x + rect1_size.x >= rect2_pos.x &&
            rect1_pos.x <= rect2_pos.x + rect2_size.x &&
            rect1_pos.y + rect1_size.y >= rect2_pos.y &&
            rect1_pos.y <= rect2_pos.y + rect2_size.y)
            return true;
        return false;
    }
}