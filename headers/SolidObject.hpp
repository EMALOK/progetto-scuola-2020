#include <SFML/Graphics.hpp>

class SolidObject
{
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;

public:
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::RectangleShape getShape();

    bool operator== (const SolidObject &);

    SolidObject(sf::Vector2f, sf::Vector2f);
    ~SolidObject();
};