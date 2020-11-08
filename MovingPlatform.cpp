#include "headers/MovingPlatform.hpp"

//  Getters

/**
 * Restituiscre una copia della posizione di partenza
 * 
 * @return Copia della posizione di partenza
 */
sf::Vector2f MovingPlatform::getStartingPosition()
{
    //  TODO
}

/**
 * Restituiscre una copia della posizione di arrivo
 * 
 * @return Copia della posizione di arrivo
 */
sf::Vector2f MovingPlatform::getEndingPosition()
{
    //  TODO
}

//  Update / Render

/**
 * Renderizzazione della piattaforma
 * 
 * @param window Finestra su cui applicare la renderizzazione
 */
void MovingPlatform::render(sf::RenderWindow* window)
{
    //  TODO
}

/**
 * Update della posizione della piattaforma
 * 
 * @param delta_time Tempo passato dall'ultima chiamata
 */
void MovingPlatform::update(sf::Time delta_time)
{
    //  TODO
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
    // TODO
}

/**
 * Distruttore
 */ 
MovingPlatform::~MovingPlatform()
{

}