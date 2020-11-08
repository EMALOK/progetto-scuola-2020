#include "headers/Coin.hpp"

//  Getters

/**
 * Restituisce una copia della posizione della moneta
 * 
 * @return position Copia della posizione della moneta
 */
sf::Vector2f Coin::getPosition()
{
    return this->shape.getPosition();
}

/**
 * Restituisce una copia della dimensione della moneta 
 * 
 * @return Copia della dimensione della moneta 
 */
sf::Vector2f Coin::getSize()
{
    return this->shape.getSize();
}

/**
 * Restituisce il valore della moneta 
 * 
 * @return Valore della moneta
 */
int Coin::getPoints()
{
    return this->points;
}

//  Setters

/**
 * Imposta la nuova posizione della moneta. 
 * Resetta min_y_pos, non utilizzare questo metodo per le animazioni 
 * 
 * @param position Nuova posizione della moneta
 */
void Coin::setPosition(sf::Vector2f position)
{
    this->shape.setPosition(position);
    this->min_y_pos = position.y;
}

/**
 * Cambia le dimensioni della moneta
 * 
 * @param size Nuova dimensione della moneta 
 */
void Coin::setSize(sf::Vector2f size)
{
    this->shape.setSize(size);
}

//  Update / Render

/**
 * Renderizzazione della moneta
 * 
 * @param window Finestra su cui applicare la renderizzazione
 */
void Coin::render(sf::RenderWindow* window)
{
    this->shape.setTexture(&texture);

    window->draw(shape);
}

/**
 * Update della posizione della moneta
 * 
 * @param delta_time Tempo passato dall'ultima chiamata
 */
void Coin::update(sf::Time delta_time)
{
    this->position_timer += delta_time.asSeconds()*this->animation_speed; //time = time + delta_time

    if (this->position_timer > 4*std::acos(0.0)) //time > 2PI
        position_timer -= 4*std::acos(0.0); //time = time - 2PI

    this->shape.setPosition(shape.getPosition().x, min_y_pos + (std::sin(position_timer + this->animation_time_offset.asSeconds()) * this->animation_height) - this->animation_height); //y = min_y + (sin(time) * a_height) - a_height
}

//  Operatori

/**
 * Vengono controllate le posizioni e le dimensioni di entrambi gli oggetti per 
 * definire l'ugualianza. 
 * 
 * @return Vero se uguali, altrimenti falso
 */
bool Coin::operator==(const Coin &r)
{
    return this->shape.getPosition() == r.shape.getPosition() && this->shape.getSize() == r.shape.getSize();
}

//  Costruttore e Distruttore

/** Moneta collezionabile
 * 
 * @param position La posizione iniziale della moneta
 * @param size Le dimensioni della moneta 
 * @param texture_path Percorso per la texture
 * @param animation_height Altezza dell'animazione
 * @param animation_speed Velocità dell'animazione
 * @param animation_time_offset Offset temporale dell'animazione
 * @param points Valore della moneta
 */
Coin::Coin(sf::Vector2f position, sf::Vector2f size, sf::String texture_path, float animation_height, float animation_speed, sf::Time animation_time_offset, int points)
{
    this->shape = sf::RectangleShape(size);
    this->shape.setPosition(position);
    this->min_y_pos = position.y;

    this->texture.loadFromFile(texture_path);

    this->animation_height = animation_height;
    this->animation_speed = animation_speed;
    this->animation_time_offset = animation_time_offset;

    this->points = points;
}

Coin::~Coin()
{

}