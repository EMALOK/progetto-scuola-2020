#include "headers/GameClass.hpp"
#include "headers/Map.hpp"
#include <iostream> //Debug


//Trova la x e la y del blocco 'Index' nel file json
sf::Vector2f Map::posBlock(int Index)
{
    return sf::Vector2f(mapDoc["blocchi"][Index]["x"].GetInt(), mapDoc["blocchi"][Index]["y"].GetInt());
}

//Trova la larghezza e l'altezza del blocco 'Index' nel file json
sf::Vector2f Map::dimBlock(int Index)
{
    return sf::Vector2f(mapDoc["blocchi"][Index]["w"].GetInt(), mapDoc["blocchi"][Index]["h"].GetInt());
}

//Trova la x e la y della moneta 'Index' nel file json
sf::Vector2f Map::posCoin(int Index)
{
    return sf::Vector2f(mapDoc["monete"][Index]["x"].GetInt(), mapDoc["blocchi"][Index]["y"].GetInt());
}

//Trova la larghezza e l'altezza della moneta 'Index' nel file json
sf::Vector2f Map::dimCoin(int Index)
{
    return sf::Vector2f(mapDoc["monete"][Index]["w"].GetInt(), mapDoc["blocchi"][Index]["h"].GetInt());
}