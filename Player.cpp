#include "headers/Player.hpp"

//getters

sf::Vector2f Player::getCoordinates()
{
    return coordinates;
}

sf::Vector2f Player::getDimensions()
{
    return dimensions;
}

sf::RectangleShape Player::getShape()
{
    return shape;
}

Player::Player(sf::Vector2f coordinates, sf::Vector2f dimensions)
{
    shape.setPosition(coordinates);
    shape.setSize(dimensions);
    shape.setFillColor(sf::Color(0, 255, 0, 255) /*verde*/);
}

Player::~Player()
{
    
}