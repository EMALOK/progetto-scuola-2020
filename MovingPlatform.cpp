#include "headers/MovingPlatform.hpp"
#include <iostream>
#include <math.h>

//  Getters

/**
 * Restituiscre una copia della posizione di partenza
 * 
 * @return Copia della posizione di partenza
 */
sf::Vector2f MovingPlatform::getStartingPosition()
{
    return this->starting_position;
}

/**
 * Restituiscre una copia della posizione di arrivo
 * 
 * @return Copia della posizione di arrivo
 */
sf::Vector2f MovingPlatform::getEndingPosition()
{
    return this->ending_position;
}

/**
 * Restituisce una copia della posizione della piattaforma
 * 
 * @return Copia della posizione della piattaforma
 */
sf::Vector2f MovingPlatform::getPosition()
{
    return this->shape.getPosition();
}

/**
 * Restituisce una copia delle dimensioni della piattaforma
 * 
 * @return Copia delle dimensioni della piattaforma
 */
sf::Vector2f MovingPlatform::getSize()
{
    return this->shape.getSize();
}

//  Update / Render

/**
 * Renderizzazione della piattaforma
 * 
 * @param window Finestra su cui applicare la renderizzazione
 */
void MovingPlatform::render(sf::RenderWindow* window)
{
    this->shape.setTexture(&texture);

    window->draw(shape);
}

/**
 * Update della posizione della piattaforma
 * 
 * @param delta_time Tempo passato dall'ultima chiamata
 */
void MovingPlatform::update(sf::Time delta_time)
{
    this->animation_timer += delta_time.asSeconds()*this->animation_speed; //time = time + delta_time

    if (this->animation_timer > 4*std::acos(0.0)) //time > 2PI
        animation_timer -= 4*std::acos(0.0); //time = time - 2PI
    
    this->shape.setPosition(GameUtils::lerp2d(starting_position, ending_position, (std::sin(animation_timer)+1)/2));
}

//  Costruttore e Distruttore

/**
 * Piattaforma mobile
 * 
 * @param starting_position Posizione di partenza
 * @param ending_position Posizione di arrivo
 * @param size Dimensioni
 * @param texture_path Percorso file della texture
 * @param animation_speed Velocità dell'animazione
 * @param animation_time_offset Offset temporale dell'animazione
 */
MovingPlatform::MovingPlatform(sf::Vector2f starting_position, sf::Vector2f ending_position, sf::Vector2f size, sf::String texture_path, float animation_speed, sf::Time animation_time_offset)
{
    this->shape = sf::RectangleShape(size);
    this->shape.setPosition(starting_position);

    this->starting_position = starting_position;
    this->ending_position = ending_position;

    this->texture.loadFromFile(texture_path);

    this->animation_speed = animation_speed;
    this->animation_time_offset = animation_time_offset;
}

/**
 * Distruttore
 */ 
MovingPlatform::~MovingPlatform()
{

}
