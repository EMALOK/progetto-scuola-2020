#include "headers/GameClass.hpp"
#include "headers/extern.hpp"
#include "headers/Map.hpp"
#include <document.h> //Creare il documento da "analizzare"
#include <filereadstream.h> //Leggere lo stream nel file json
#include <fstream> //Leggere e chiudere il file json
#include <iostream> //Debug

Map::Map(const char* map, Game *game)
{
    FILE *fp = fopen(map, "rb"); //Leggo il file
    char buf[0XFFFF];   //inizializzo un carattere buffering corrispondente al numero di righe da analizzare (In questo caso altissimo)
    rapidjson::FileReadStream input(fp, buf, sizeof(buf)); //Leggo lo stream
    rapidjson::Document mapDoc; //Creo il documento
    mapDoc.ParseStream(input); //Lo analizzo
    fclose(fp); //Chiudo il file
    
    //Prendere tutte le variabili della mappa
    /* TO DO */
    //Pavimento
    SolidObject pavimento = SolidObject(sf::Vector2f(mapDoc["pavimento"]["posx"].GetFloat(), mapDoc["pavimento"]["posy"].GetFloat()), sf::Vector2f(mapDoc["pavimento"]["sizex"].GetFloat(), mapDoc["pavimento"]["sizey"].GetFloat())); //Creo il pavimento dal file json
    game->addSolidObject(pavimento); //Aggiungo al vettore dei SolidObject il pavimento appena creato

    //Ostacolo
    SolidObject ostacolo = SolidObject(sf::Vector2f(mapDoc["ostacolo"]["posx"].GetFloat(), mapDoc["ostacolo"]["posy"].GetFloat()), sf::Vector2f(mapDoc["ostacolo"]["sizex"].GetFloat(), mapDoc["ostacolo"]["sizey"].GetFloat())); //Creo l'ostacolo dal file json
    game->addSolidObject(ostacolo); //Aggiungo al vettore dei SolidObject l'ostacolo appena creato

    //Secondo piano
    SolidObject secondopiano = SolidObject(sf::Vector2f(mapDoc["secondoPiano"]["posx"].GetFloat(), mapDoc["secondoPiano"]["posy"].GetFloat()), sf::Vector2f(mapDoc["secondoPiano"]["sizex"].GetFloat(), mapDoc["secondoPiano"]["sizey"].GetFloat())); //Creo il secondo piano dal file json
    game->addSolidObject(secondopiano); //Aggiungo al vettore dei SOlidObject il secondo piano appena creato

    //Monete
    Coin moneta1 = Coin(sf::Vector2f(mapDoc["Monete"]["Moneta1"]["posx"].GetFloat(), mapDoc["Monete"]["Moneta1"]["posy"].GetFloat()), sf::Vector2f(mapDoc["Monete"]["Moneta1"]["sizex"].GetFloat(), mapDoc["Monete"]["Moneta1"]["sizey"].GetFloat()), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(0), 10);
    game->addCoin(moneta1);
    Coin moneta2 = Coin(sf::Vector2f(mapDoc["Monete"]["Moneta2"]["posx"].GetFloat(), mapDoc["Monete"]["Moneta2"]["posy"].GetFloat()), sf::Vector2f(mapDoc["Monete"]["Moneta2"]["sizex"].GetFloat(), mapDoc["Monete"]["Moneta2"]["sizey"].GetFloat()), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(1), 20);
    game->addCoin(moneta2);
    Coin moneta3 = Coin(sf::Vector2f(mapDoc["Monete"]["Moneta3"]["posx"].GetFloat(), mapDoc["Monete"]["Moneta3"]["posy"].GetFloat()), sf::Vector2f(mapDoc["Monete"]["Moneta3"]["sizex"].GetFloat(), mapDoc["Monete"]["Moneta3"]["sizey"].GetFloat()), "./immagini/gem-1.png", 30.f, 2.f, sf::seconds(2), 30);
    game->addCoin(moneta3);

}
