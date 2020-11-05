#include "headers/Player.hpp"

//Getters

sf::Vector2f Player::getPosition()
{
    return position;
}

sf::Vector2f Player::getSize()
{
    return size;
}

sf::Vector2f Player::getSpeed()
{
    return speed;
}

sf::Vector2f Player::getAcceleration()
{
    return acceleration;
}

sf::RectangleShape Player::getShape()
{
    return shape;
}

//Setters

void Player::setCoordinates(sf::Vector2f position)
{
    this->position = position;
}

void Player::setDimensions(sf::Vector2f size)
{
    this->size = size;
}

void Player::setSpeed(sf::Vector2f speed)
{
    this->speed = speed;
}

void Player::setAcceleration(sf::Vector2f acceleration)
{
    this->acceleration = acceleration;
}

void Player::reloadShape()
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color(0, 255, 0, 255) /*verde*/);
}

//Costruttore e distruttore

/** Oggetto del player
 * 
 * @param position Coordinate del player
 * @param size Dimensioni del player
 */
Player::Player(sf::Vector2f position, sf::Vector2f size)
{
    this->position = position;
    this->size = size;
    reloadShape();
}

Player::~Player()
{
    
}
