#include "GameClass.hpp"

int main()
{
    //game window
    Game game;

    //game loop
    while (game.isGameOpen())
    {
        game.update();
        game.render();
    }

    return 0;
}