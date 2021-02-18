#include <SFML/Graphics.hpp>
#include "rapidJson/document.h"       //Creare il documento da "analizzare"
#include "rapidJson/filereadstream.h" //Leggere lo stream nel file json
#include <fstream>                    //Leggere e chiudere il file json
#include <iostream>

class Map
{
public:
    //  Metodi oggetti solidi
    sf::Vector2f posBlock(int Index);
    sf::Vector2f dimBlock(int Index);
    //  Metodi monete
    sf::Vector2f posCoin(int Index);
    sf::Vector2f dimCoin(int Index);

    rapidjson::Document mapDoc;

    //  Costrutte e Distruttore
    Map(const char *map);
    ~Map();
};
