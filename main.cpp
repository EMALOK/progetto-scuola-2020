#include "headers/GameClass.hpp"

int main()
{
    //game window
    Game game;

    SolidObject pavimento = SolidObject(sf::Vector2f(0, 800), sf::Vector2f(1400, 100));
    game.addSolidObject(pavimento);

    const sf::Time SPF = sf::milliseconds(16); //16ms per frame

    sf::Clock clock; //start timer

    //game loop
    while (game.isGameOpen())
    {
        sf::Time elapsed = clock.restart();
        game.update(elapsed);
        game.render();
    }

    return 0;
}