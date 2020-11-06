#include "headers/SolidObject.hpp"

//getters

sf::Vector2f SolidObject::getPosition()
{
    return position;
}

sf::Vector2f SolidObject::getSize()
{
    return size;
}

sf::RectangleShape SolidObject::getShape()
{
    return shape;
}

//operatore ==
bool SolidObject::operator==(const SolidObject &r)
{
    return position == r.position && size == r.size;
}

//costruttore e distruttore

/** Oggetto solido nel mondo
 * 
 * @param position Coordinate dell'oggetto solido
 * @param size Dimensioni dell'oggetto
 */
SolidObject::SolidObject(sf::Vector2f position, sf::Vector2f size)
{
    this->position = position;
    this->size = size;
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color(255, 0, 0, 255) /*rosso*/);
}

SolidObject::~SolidObject()
{

}