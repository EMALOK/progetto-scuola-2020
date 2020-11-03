#include "GameClass.hpp"

int main()
{
    //game window
    Game game;

    const sf::Time SPF = sf::milliseconds(16); //16ms per frame

    sf::Clock clock; //start timer

    //game loop
    while (game.isGameOpen())
    {
        sf::Time elapsed = clock.restart();
        game.update(elapsed);
        game.render();
        if (SPF.asMilliseconds() >= elapsed.asMilliseconds())
            sf::sleep(sf::milliseconds(SPF.asMilliseconds() - elapsed.asMilliseconds()));
    }

    return 0;
}