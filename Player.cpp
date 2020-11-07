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

void Player::setTexture(sf::String path)
{
    texture.loadFromFile(path);
}

//Rendering

void Player::reloadShape()
{
    shape.setPosition(position);
    shape.setSize(size);
}

void Player::render(sf::RenderWindow* window)
{
    reloadShape();

    shape.setTexture(&texture);

    window->draw(shape);
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
