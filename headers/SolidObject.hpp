#pragma once
#include <SFML/Graphics.hpp>

class SolidObject
{
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;

public:
    //  Getters

    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::RectangleShape getShape();

    //  Operatori

    bool operator== (const SolidObject &);

    //  Costruttore e Distruttore

    SolidObject(sf::Vector2f, sf::Vector2f);
    ~SolidObject();
};