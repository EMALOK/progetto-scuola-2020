#include "headers/SolidObject.hpp"

//getters

sf::Vector2f SolidObject::getCoordinates()
{
    return coordinates;
}

sf::Vector2f SolidObject::getDimensions()
{
    return dimensions;
}

sf::RectangleShape SolidObject::getShape()
{
    return shape;
}

//costruttore e distruttore

SolidObject::SolidObject(sf::Vector2f coordinates, sf::Vector2f dimensions)
{
    shape.setPosition(coordinates);
    shape.setSize(dimensions);
    shape.setFillColor(sf::Color(255, 0, 0, 255) /*rosso*/);
}

SolidObject::~SolidObject()
{

}