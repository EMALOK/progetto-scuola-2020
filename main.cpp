#include "headers/GameClass.hpp"
#include "headers/Map.hpp"
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

    //Loader mappa
    Map("./Maps/Prova.json", &game);

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