#include "headers/Player.hpp"

//Getters

sf::Vector2f Player::getCoordinates()
{
    return coordinates;
}

sf::Vector2f Player::getDimensions()
{
    return dimensions;
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

void Player::setCoordinates(sf::Vector2f coordinates)
{
    this->coordinates = coordinates;
}

void Player::setDimensions(sf::Vector2f dimensions)
{
    this->dimensions = dimensions;
}

void Player::setSpeed(sf::Vector2f speed)
{
    this->speed = speed;
}

void Player::setAcceleration(sf::Vector2f acceleration)
{
    this->acceleration = acceleration;
}

//Update

void Player::update(sf::Time elapsed)
{
    //accelerazione in base ai i tasti wasd
    //maxxare la velocità dupo un certo valore v max
    //lerp verso 0 per la velocità
    //fisica
    //TODO
}

void Player::reloadShape()
{
    shape.setPosition(coordinates);
    shape.setSize(dimensions);
    shape.setFillColor(sf::Color(0, 255, 0, 255) /*verde*/);
}

//Costruttore e distruttore

Player::Player(sf::Vector2f coordinates, sf::Vector2f dimensions)
{
    reloadShape();
}

Player::~Player()
{
    
}
