#include "headers/GameClass.hpp"

//Funzioni

void Game::update(sf::Time delta_time)
{
    pollEvents();
}

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
    // TODO
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
}