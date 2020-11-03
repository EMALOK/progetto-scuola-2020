#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow *window; //oggetto della finestra (puntatore)
    sf::VideoMode videomode;
    sf::Event event;

    //funzioni private
    void initVars();
    void initWindow();

public:
    //costruttore e distruttore
    Game();
    ~Game();
    
    //funzioni
    void update();
    void render();

    bool isGameOpen();
    void pollEvents();
};