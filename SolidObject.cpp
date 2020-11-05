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

//operatore ==
bool SolidObject::operator==(const SolidObject &r)
{
    return coordinates == r.coordinates && dimensions == r.coordinates;
}

//costruttore e distruttore

/** Oggetto solido nel mondo
 * 
 * @param coordinates Coordinate dell'oggetto solido
 * @param dimensions Dimensioni dell'oggetto
 */
SolidObject::SolidObject(sf::Vector2f coordinates, sf::Vector2f dimensions)
{
    this->coordinates = coordinates;
    this->dimensions = dimensions;
    shape.setPosition(coordinates);
    shape.setSize(dimensions);
    shape.setFillColor(sf::Color(255, 0, 0, 255) /*rosso*/);
}

SolidObject::~SolidObject()
{

}