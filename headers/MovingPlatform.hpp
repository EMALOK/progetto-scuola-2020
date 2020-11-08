#include <SFML/Graphics.hpp>

class MovingPlatform
{
private:
    //  Rendering

    sf::RectangleShape shape;
    sf::Texture texture;

    //  Posizioni

    sf::Vector2f starting_position;
    sf::Vector2f ending_position;


    //  Animazioni

    float animation_timer = 0;
    float animation_speed;
    sf::Time animation_time_offset;

public:
    //  Getters
    
    sf::Vector2f getStartingPosition();
    sf::Vector2f getEndingPosition();

    //  Update / Render

    void render(sf::RenderWindow*);
    void update(sf::Time);

    //  Costruttore e Distruttore
    
    MovingPlatform(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::String, float, sf::Time);
    ~MovingPlatform();
};
