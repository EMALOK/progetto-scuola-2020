#include "headers/Player.hpp"

//  Getters

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

/**
 * Restituisce il punteggio del giocatore
 * 
 * @return Punteggio del giocatore
 */
int Player::getPoints()
{
    return this->points;
}

//  Setters

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

/**
 * Imposta il punteggio del giocatore
 * 
 * @param points Nuovo punteggio
 */
void Player::setPoints(int points)
{
    this->points = points;
}

/**
 * Incrementa il punteggio del giocatore
 * 
 * @param points Incremento del punteggio
 */
void Player::addPoints(int points)
{
    this->points += points;
}

//  Rendering

void Player::reloadShape()
{
    shape.setPosition(position);
    shape.setSize(size);
}

void Player::render(sf::RenderWindow *window)
{
    reloadShape();

    shape.setTexture(&texture);

    window->draw(shape);
}

//  Costruttore e distruttore

/** Giocatore in scena
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
