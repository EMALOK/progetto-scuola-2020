#pragma once
#include <SFML/Graphics.hpp>
#include <document.h> //Creare il documento da "analizzare"
#include <filereadstream.h> //Leggere lo stream nel file json
#include <fstream> //Leggere e chiudere il file json
#include <iostream>

class Map
{
public:
    Map() { }

    Map(const char* map)
    {
        FILE *fp = fopen(map, "rb"); //Leggo il file
        char buf[0XFFFF];   //inizializzo un carattere buffering corrispondente al numero di righe da analizzare (In questo caso altissimo)
        rapidjson::FileReadStream input(fp, buf, sizeof(buf)); //Leggo lo stream
        mapDoc.ParseStream(input); //Lo analizzo
        fclose(fp); //Chiudo il file
    }

    //Metodi

    sf::Vector2f posBlock(int Index);
    sf::Vector2f dimBlock(int Index);

    sf::Vector2f posCoin(int Index);
    sf::Vector2f dimCoin(int Index);

    void debug()
    {
        std::cout << mapDoc["blocchi"][2]["x"].GetInt() << "\n";
        std::cout << mapDoc["blocchi"][2]["y"].GetInt() << "\n";
    }

private:
    rapidjson::Document mapDoc;
};