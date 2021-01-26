#include "headers/SolidObject.hpp"

//  Getters

/**
 * Restituisce una copia della posizione dell'oggetto solido
 * 
 * @return position Copia della posizione dell'oggetto solido
 */
sf::Vector2f SolidObject::getPosition()
{
    return position;
}

/**
 * Restituisce una copia della dimensione dell'oggetto solido
 * 
 * @return Copia della dimensione dell'oggetto solido 
 */
sf::Vector2f SolidObject::getSize()
{
    return size;
}

/**
 * Restituisce una copia della shape dell'oggetto solido
 * 
 * @return Copia della shape dell'oggetto solido
 */
sf::RectangleShape SolidObject::getShape()
{
    return shape;
}

//  Operatori

/**
 * Vengono controllate le posizioni e le dimensioni di entrambi gli oggetti per 
 * definire l'ugualianza. 
 * 
 * @return Vero se uguali, altrimenti falso
 */
bool SolidObject::operator==(const SolidObject &r)
{
    return position == r.position && size == r.size;
}

//  Costruttore e Distruttore

/** 
 * Oggetto solido
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

/**
 * Distruttore
 */
SolidObject::~SolidObject()
{
}
