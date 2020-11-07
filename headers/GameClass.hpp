#include <SFML/Graphics.hpp>
#include "SolidObject.hpp"
#include "Player.hpp"
#include "Coin.hpp"
#include <vector>

class Game
{
private:
    //  Variabili della finestra
    sf::RenderWindow *window; //oggetto della finestra (puntatore)
    sf::View *view;
    sf::VideoMode videomode;
    sf::Event event;

    //  Variabili di gioco
    std::vector<SolidObject> solidObjects; //Oggetti solidi presenti nella scena
    std::vector<Coin> coins; //Monete presenti nella scena
    Player *player; //Puntatore al player

    //  Inizializzazioni
    void initVars();
    void initWindow();

    //  Rendering
    void renderSolidObjects();
    void renderCoins();
    void renderPlayer();

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

    Player *getPlayer();

    //  Costruttore e Distruttore
    Game();
    ~Game();
};