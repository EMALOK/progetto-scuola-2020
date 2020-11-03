#include <SFML/Graphics.hpp>
#include "SolidObject.hpp"
#include <vector>

class Game
{
private:
    //Variabili della finestra
    sf::RenderWindow *window; //oggetto della finestra (puntatore)
    sf::VideoMode videomode;
    sf::Event event;

    //Variabili di gioco
    std::vector<SolidObject> solidObjects; //Oggetti solidi presenti nel mondo

    //funzioni private
    void initVars();
    void initWindow();

    void renderSolidObjects();

public:
    //costruttore e distruttore
    Game();
    ~Game();
    
    //funzioni
    void update(sf::Time);
    void render();

    bool isGameOpen();
    void pollEvents();

    void addSolidObject(SolidObject);
    void removeSolidObject(SolidObject);
};