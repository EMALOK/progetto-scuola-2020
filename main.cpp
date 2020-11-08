#include "headers/GameClass.hpp"

int main()
{
    //game window
    Game game;

    //generazione pavimento
    SolidObject pavimento = SolidObject(sf::Vector2f(-1000, 800), sf::Vector2f(10000, 100));
    game.addSolidObject(pavimento);

    //generazione ostacolo
    SolidObject ostacolo = SolidObject(sf::Vector2f(700, 800-50), sf::Vector2f(50, 50));
    game.addSolidObject(ostacolo);

    //generazione secondo piano
    SolidObject secondopiano = SolidObject(sf::Vector2f(0, 550), sf::Vector2f(1000, 50));
    game.addSolidObject(secondopiano);


    //posizionamento player
    game.getPlayer()->setCoordinates(sf::Vector2f(1400 / 2 - 50, 0));
    game.getPlayer()->setDimensions(sf::Vector2f(50, 50));
    game.getPlayer()->setTexture("./immagini/big-crate.png");

    //posizionamento moneta
    Coin moneta = Coin(sf::Vector2f(200, 790-26), sf::Vector2f(30, 26), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(0), 10);
    game.addCoin(moneta);
    Coin moneta2 = Coin(sf::Vector2f(250, 790-26), sf::Vector2f(30, 26), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(1), 20);
    game.addCoin(moneta2);
    game.addCoin(Coin(sf::Vector2f(300, 790-26), sf::Vector2f(30, 26), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(2), 30));

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