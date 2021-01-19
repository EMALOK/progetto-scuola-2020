#include <SFML/Graphics.hpp>
#include <iostream> //debug
#include <math.h>

class Coin
{
private:
    sf::RectangleShape shape;
    sf::Texture texture;

    float min_y_pos;
    float position_timer = 0;

    float animation_height;
    float animation_speed;
    sf::Time animation_time_offset;

    int points;
public:
    //  Getters

    sf::Vector2f getPosition();
    sf::Vector2f getSize();

    int getPoints();

    //  Setters

    void setPosition(sf::Vector2f);
    void setSize(sf::Vector2f);
    void setPositionTimer(sf::Time);

    //  Update / Render

    void render(sf::RenderWindow*);
    void update(sf::Time);

    //  Operatori

    bool operator== (const Coin &);

    //  Costruttore e Distruttore

    Coin(sf::Vector2f, sf::Vector2f, sf::String, float, float, sf::Time, int);
    ~Coin();
};