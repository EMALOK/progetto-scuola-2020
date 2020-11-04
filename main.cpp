#include "headers/GameClass.hpp"

int main()
{
    //game window
    Game game;

    //generazione pavimento
    SolidObject pavimento = SolidObject(sf::Vector2f(0, 800), sf::Vector2f(1400, 100));
    game.addSolidObject(pavimento);
    
    //posizionamento player
    game.getPlayer()->setCoordinates(sf::Vector2f(0, 0));
    game.getPlayer()->setDimensions(sf::Vector2f(50, 50));


    //game loop
    sf::Clock clock; //start timer
    while (game.isGameOpen())
    {
        sf::Time elapsed = clock.restart();
        game.update(elapsed);
        game.render();
    }

    return 0;
}