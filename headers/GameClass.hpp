#include "MovingPlatform.hpp"
#include "SolidObject.hpp"
#include "GameUtils.hpp"
#include "Player.hpp"
#include <iostream>
#include "Coin.hpp"
#include <vector>
#include <string>

class Game
{
private:
    //  Variabili della finestra
    sf::RenderWindow *window; //oggetto della finestra (puntatore)
    sf::View *view;
    sf::VideoMode videomode;
    sf::Event event;
    sf::Font font; //font utilizzato nel gioco

    //  Variabili di gioco
    std::vector<SolidObject> solidObjects; //Oggetti solidi presenti nella scena
    std::vector<Coin> coins; //Monete presenti nella scena
    std::vector<MovingPlatform> platforms; //Piattaforme mobili nella scena
    Player *player; //Puntatore al player

    //  Inizializzazioni
    void initVars();
    void initWindow();

    //  Rendering
    void renderSolidObjects();
    void renderPlatforms();
    void renderCoins();
    void renderPlayer();
    void renderOverlay();

public:
    
    //  Update e Render
    void update(sf::Time);
    void render();

    //  Funzioni per la finestra
    bool isGameOpen();
    void pollEvents();

    //  Controllo degli oggetti nella scena

    //SolidObject
    void addSolidObject(SolidObject);
    void removeSolidObject(SolidObject);
    void clearSolidObjects();
    //Coin
    void addCoin(Coin);
    void removeCoin(Coin);
    void clearCoins();
    //MovingPlatform
    void addPlatform(MovingPlatform);
    void removePlatform(MovingPlatform);
    void clearPlatforms();

    Player *getPlayer();

    //  Costruttore e Distruttore
    Game();
    ~Game();
};