#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Vector2f coordinates;
    sf::Vector2f dimensions;
    sf::RectangleShape shape;

    sf::Vector2f speed;
    sf::Vector2f acceleration;

public:
    //Getters
    sf::Vector2f getCoordinates();
    sf::Vector2f getDimensions();
    sf::RectangleShape getShape();

    sf::Vector2f getSpeed();
    sf::Vector2f getAcceleration();

    //Setters
    void setCoordinates(sf::Vector2f);
    void setDimensions(sf::Vector2f);

    void setSpeed(sf::Vector2f);
    void setAcceleration(sf::Vector2f);

    //Update
    void update(sf::Time);
    void reloadShape();

    //Costruttori e distruttori
    Player(sf::Vector2f, sf::Vector2f);
    ~Player();
};