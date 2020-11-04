#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Vector2f coordinates;
    sf::Vector2f dimensions;
    sf::RectangleShape shape;

    float speed;
    float acceleration;

public:
    //Getters
    sf::Vector2f getCoordinates();
    sf::Vector2f getDimensions();
    sf::RectangleShape getShape();

    float getSpeed();
    float getAcceleration();

    //Setters
    void setCoordinates(sf::Vector2f);
    void setDimensions(sf::Vector2f);

    void setSpeed(float);
    void setAcceleration(float);

    //Update
    void update(sf::Time);
    void reloadShape();

    //Costruttori e distruttori
    Player(sf::Vector2f, sf::Vector2f);
    ~Player();
};