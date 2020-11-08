#include <SFML/Graphics.hpp>
#include <math.h>

namespace GameUtils
{
    float lerp1d(float, float, float);

    sf::Vector2f lerp2d(sf::Vector2f, sf::Vector2f, float);

    sf::Vector2f scalare(sf::Vector2f, float);

    bool discordi(float, float);

    bool colliding(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f);

    float getSquareMagnitude(sf::Vector2f*);

    float getMagnitude(sf::Vector2f*);

    void setMagnitude(sf::Vector2f*, float);

    sf::Vector2f setMagnitude(sf::Vector2f, float);
}
