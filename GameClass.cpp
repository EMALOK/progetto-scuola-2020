#include "headers/GameClass.hpp"
#include "headers/GameUtils.hpp"
#include <iostream> //debug 

#define K_DEC 4.f //costante di decelerazione
#define A_SPEED 350 //accelerazione orizzontale
#define PLAYER_MAX_VH 300 //velocita orizzontale massima del player

//Funzioni

//Update

void Game::update(sf::Time delta_time)
{
    pollEvents();

    /*  CONTROLLO TASTI MOVIMENTO   */

    //destra
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->setAcceleration(sf::Vector2f(A_SPEED, player->getAcceleration().y));
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //se destra e sinistra non sono premuti
    {
        player->setAcceleration(sf::Vector2f(0, player->getAcceleration().y)); //impostiamo l'accelerazione a 0
    }
    
    //sinistra
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->setAcceleration(sf::Vector2f(-A_SPEED, player->getAcceleration().y));
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //se destra e sinistra non sono premuti
    {
        player->setAcceleration(sf::Vector2f(0, player->getAcceleration().y)); //impostiamo l'accelerazione a 0
    }
    //alto
    // TODO

    /*  FISICA  */
    
    /*  DEBUG   */
    std::cout << "acc.x " << player->getAcceleration().x << " ";
    std::cout << "acc.y " << player->getAcceleration().y << " ";
    std::cout << "vel.x " << player->getSpeed().x << " ";
    std::cout << "vel.y " << player->getSpeed().y << "\n";
    /*          */

    //  Decelerazioni per attrito
    //quando l'accelerazione è uguale a 0 -> applica attrito
    if (player->getAcceleration().x == 0 || GameUtils::discordi(player->getAcceleration().x, player->getSpeed().x))
        player->setSpeed(sf::Vector2f(GameUtils::lerp1d(player->getSpeed().x, 0.f, K_DEC * delta_time.asSeconds()), player->getSpeed().y));
    if (player->getAcceleration().y == 0 || GameUtils::discordi(player->getAcceleration().y, player->getSpeed().y))
        player->setSpeed(sf::Vector2f(player->getSpeed().x, GameUtils::lerp1d(player->getSpeed().y, 0.f, K_DEC * delta_time.asSeconds())));
    
    //  Se la velocità è molto vicina a 0, impostarla direttamente a 0 (solo quando non è presente un'accelerazione)
    if (abs(player->getSpeed().x) <= 0.1f && player->getAcceleration().x == 0)
        player->setSpeed(sf::Vector2f(0.f, player->getSpeed().y));
    if (abs(player->getSpeed().y) <= 0.1f && player->getAcceleration().y == 0)
        player->setSpeed(sf::Vector2f(player->getSpeed().x, 0.f));

    //  Inerzia
    player->setSpeed(player->getSpeed() + GameUtils::scalare(player->getAcceleration(), delta_time.asSeconds())); // v = v + (a * dt)

    //  Controllo velocità orizzontale massima
    if (player->getSpeed().x >= PLAYER_MAX_VH)
        player->setSpeed(sf::Vector2f(PLAYER_MAX_VH, player->getSpeed().y));
    else if (player->getSpeed().x <= -PLAYER_MAX_VH)
        player->setSpeed(sf::Vector2f(-PLAYER_MAX_VH, player->getSpeed().y));

    // Update Posizioni e controllo collisioni
    sf::Vector2f next_player_pos(player->getCoordinates() + GameUtils::scalare(player->getSpeed(), delta_time.asSeconds())); // p = p + (v * dt)
    player->setCoordinates(next_player_pos);

}

//Render

void Game::render()
{
    window->clear();

    //DRAW
    renderSolidObjects(); //render oggetti solidi
    renderPlayer(); //render player



    window->display();
}

void Game::renderSolidObjects()
{
    for (auto currSO : solidObjects)
    {
        window->draw(currSO.getShape());
    }
}

void Game::renderPlayer()
{
    player->reloadShape();
    window->draw(player->getShape());
}

//Window functions

bool Game::isGameOpen()
{
    return window->isOpen();
}

void Game::pollEvents()
{
    while(window->pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed: //chiusura del gioco da Windows
                window->close();
                break;

            case sf::Event::KeyPressed: //chiusura del gioco dal tasto Esc
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
        }
    }
}

void Game::initVars()
{
    //iniz. oggetto finestra
    window = nullptr;

    //All'avvio del gioco il player sarà posizionato alle coordinate 0, 0 con grandezza 0, 0
    player = new Player(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
}

void Game::initWindow()
{
    //grandezza della finestra impostata alla grandezza dello schermo
    videomode.height = 900;
    videomode.width = 1400;
    
    //apri finestra del gioco
    window = new sf::RenderWindow(videomode, "Gioco", sf::Style::Close | sf::Style::Titlebar);

    window->setFramerateLimit(120);
}

//Solid Objects

void Game::addSolidObject(SolidObject solidObject)
{
    solidObjects.push_back(solidObject);
}

void Game::removeSolidObject(SolidObject solidObject)
{
    int index = 0;
    for (auto currSO : solidObjects)
    {
        if (currSO == solidObject)
        {
            solidObjects.erase(solidObjects.begin() + index);
        }
        index++;
    }
}

// Player

Player *Game::getPlayer()
{
    return player;
}

//Costruttore e Distruttore

Game::Game()
{
    initVars();
    initWindow();
}

Game::~Game()
{
    delete window;
    delete player;
}