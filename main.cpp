#include "headers/GameClass.hpp"
#include "headers/Sign-in&Sign-up.hpp"
#include "headers/ScoreUpdater.hpp"
#include "headers/extern.hpp"
#include <iostream>

int main()
{

    sf::Font arial;
    arial.loadFromFile("C:/Users/super/AppData/Local/Roblox/Versions/version-63d5cf76777d4db4/content/fonts/arial.ttf");

    sf::Font ThaleahFat;
    ThaleahFat.loadFromFile("C:/Users/super/Desktop/progetto-scuola-2020/immagini/ThaleahFat_TTF.ttf");

    startWindow(arial, ThaleahFat);
    if(ClosedWindow) return 0;


    //game window
    Game game;

    //Loader mappa (TODO)
    //Map("./Maps/Prova.json", &game);


    //generazione pavimento
    SolidObject pavimento = SolidObject(sf::Vector2f(-1000, 800), sf::Vector2f(10000, 100));
    game.addSolidObject(pavimento);

    //generazione ostacolo
    SolidObject ostacolo = SolidObject(sf::Vector2f(700, 800-50), sf::Vector2f(50, 50));
    game.addSolidObject(ostacolo);

    //generazione secondo piano
    SolidObject secondopiano = SolidObject(sf::Vector2f(0, 550), sf::Vector2f(1000, 50));
    game.addSolidObject(secondopiano);

    //posizionamento moneta
    Coin moneta = Coin(sf::Vector2f(200, 790-26), sf::Vector2f(30, 26), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(0), 10);
    game.addCoin(moneta);
    Coin moneta2 = Coin(sf::Vector2f(250, 790-26), sf::Vector2f(30, 26), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(1), 20);
    game.addCoin(moneta2);
    game.addCoin(Coin(sf::Vector2f(300, 790-26), sf::Vector2f(30, 26), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(2), 30));

    //posizionamento player
    game.getPlayer()->setCoordinates(sf::Vector2f(1400 / 2 - 50, 0));
    game.getPlayer()->setDimensions(sf::Vector2f(50, 50));
    game.getPlayer()->setTexture("./immagini/big-crate.png");

    //game loop
    sf::Clock clock; //start timer
    while (game.isGameOpen())
    {
        sf::Time elapsed = clock.restart();
        game.update(elapsed);
        game.render(BestScore);
    }


    
    if(BestScore < NewBestScore)
    {
        ScoreUpdater(Username, Password, NewBestScore);
    }
    


    return 0;
}
