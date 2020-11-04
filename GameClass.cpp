#include "headers/GameClass.hpp"

//Funzioni

//Update

void Game::update(sf::Time delta_time)
{
    pollEvents();
}

//Render

void Game::render()
{
    window->clear();

    //DRAW
    renderSolidObjects();


    window->display();
}

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

//Funzioni private

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

void Game::renderSolidObjects()
{
    for (auto currSO : solidObjects)
    {
        window->draw(currSO.getShape());
    }
}

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

//Player getter

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