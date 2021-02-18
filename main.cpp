#include "headers/GameClass.hpp"
#include "headers/Sign-in&Sign-up.hpp"
#include "headers/ScoreUpdater.hpp"
#include "headers/extern.hpp"
#include "headers/Map.hpp"
#include <iostream>

void loadLevel(int &levelIndex, Game *game)
{
    game->resetView();
    game->clearCoins();
    game->clearSolidObjects();

    static const char *levelsArray[5] = {"./Maps/Tutorial.json", "./Maps/Livello1.json", "./Maps/Livello2.json", "./Maps/Livello3.json", "./Maps/Livello4.json"};

    Map Livelli(levelsArray[levelIndex]);

    //generazione blocchi solidi
    for (auto &v : Livelli.mapDoc["blocchi"].GetArray())
    {
        game->addSolidObject(SolidObject(sf::Vector2f(v["x"].GetInt(), v["y"].GetInt()), sf::Vector2f(v["w"].GetInt(), v["h"].GetInt()))); //Itero per ogni blocco che è nell'array "blocchi"
    }

    //generazione monete
    for (auto &v : Livelli.mapDoc["monete"].GetArray())
    {
        game->addCoin(Coin(sf::Vector2f(v["x"].GetInt(), v["y"].GetInt()), sf::Vector2f(v["w"].GetInt(), v["h"].GetInt()), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(0), 10)); //Itero per ogni moneta che è nell'array "monete"
    }

    //posizionamento player
    game->getPlayer()->revive();
    game->getPlayer()->setCoordinates(sf::Vector2f(1400 / 2 - 50, 0));
    game->getPlayer()->setDimensions(sf::Vector2f(50, 50));
    game->getPlayer()->setTexture("./immagini/big-crate.png");
}

int main()
{
    sf::Font arial;
    if (!arial.loadFromFile("immagini/font/arial.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Font ThaleahFat;
    if (!ThaleahFat.loadFromFile("immagini/font/ThaleahFat.ttf"))
    {
        return EXIT_FAILURE;
    }

    startWindow(arial, ThaleahFat);
    if (ClosedWindow)
        return 0;

    sf::Clock clock; //start timer
    int levelIndex = 0;

    //game window
    Game game;
    
    loadLevel(levelIndex, &game);

    //game loop
    while (game.isGameOpen())
    {
        sf::Time elapsed = clock.restart();
        game.update(elapsed);
        game.render(BestScore);
        if (game.levelCompleted) //vai al livello successivo
        {
            levelIndex++;
            loadLevel(levelIndex, &game);
        }
        if (!game.isPlayerAlive())
        {
            loadLevel(levelIndex, &game);
        }
    }

    if (BestScore < NewBestScore)
    {
        ScoreUpdater(Username, Password, NewBestScore);
    }

    return 0;
}
