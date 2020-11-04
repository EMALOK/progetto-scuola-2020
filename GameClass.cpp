#include "headers/GameClass.hpp"

//Funzioni

//Update

void Game::update(sf::Time delta_time)
{
    pollEvents();

    sf::Vector2f velocity(sf::Vector2f(0.0f, 0.0f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x = Game::player->getSpeed();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x = -(Game::player->getSpeed());
    
    Game *player.move(velocity.x, 0);
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