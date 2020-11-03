#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Vector2f coordinates;
    sf::Vector2f dimensions;
    sf::RectangleShape shape;

public:
    sf::Vector2f getCoordinates();
    sf::Vector2f getDimensions();
    sf::RectangleShape getShape();

    Player(sf::Vector2f, sf::Vector2f);
    ~Player();
};