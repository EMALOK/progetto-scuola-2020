#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;

    sf::Vector2f speed;
    sf::Vector2f acceleration;

    sf::Texture texture;

    int points = 0;

    bool alive = true;

public:
    //  Getters

    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::RectangleShape getShape();

    sf::Vector2f getSpeed();
    sf::Vector2f getAcceleration();

    int getPoints();

    bool isAlive();

    //  Setters

    void setCoordinates(sf::Vector2f);
    void setDimensions(sf::Vector2f);

    void setSpeed(sf::Vector2f);
    void setAcceleration(sf::Vector2f);

    void setTexture(sf::String);

    void setPoints(int);
    void addPoints(int);

    void kill();
    void revive();

    //  Rendering

    void reloadShape();
    void render(sf::RenderWindow*);

    //  Costruttore e distruttore

    Player(sf::Vector2f, sf::Vector2f);
    ~Player();
};
