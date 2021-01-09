#include "headers/GameUtils.hpp"

/**
 * Funzioni di utilità generale
 */
namespace GameUtils {

    /** 
     * Interpolazione lineare di due valori
     * 
     * @param a Valore di partenza, ritornato con k = 0
     * @param b Valore di fine, ritornato con k = 1
     * @param k Valore utilizzato per l'interpolazione
     * 
     * @return Interpolazione lineare di a e b con interpolante k
     */
    float lerp1d(float a, float b, float k)
    {
        return (1 - k) * a + k * b;
    }

    /** 
     * Interpolazione lineare di due vettori 2d
     * 
     * @param a Valore di partenza, ritornato con k = 0
     * @param b Valore di fine, ritornato con k = 1
     * @param k Valore utilizzato per l'interpolazione
     * 
     * @return Interpolazione lineare di a e b con interpolante k
     */
    sf::Vector2f lerp2d(sf::Vector2f a, sf::Vector2f b, float k)
    {
        return sf::Vector2f(lerp1d(a.x, b.x, k), lerp1d(a.y, b.y, k));
    }

    /**
     * Calcolo dello scalare tra un vettore ed un numero
     */
    sf::Vector2f scalare(sf::Vector2f v, float s) // v * s
    {
        v.x *= s;
        v.y *= s;
        return v;
    }

    /** Controllo se due valori sono discordi
     * 
     * @param a Valore a
     * @param b Valore b
     * 
     * @return Vero se discordi, altrimenti falso
     */
    bool discordi(float a, float b)
    {
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
            return true;
        return false;
    }

    /** Controllo collisioni
     * 
     * @param rect1_pos Posizione del primo rettangolo
     * @param rect1_size Dimensioni del primo rettangolo
     * @param rect2_pos Posizione del secondo rettangolo
     * @param rect2_size Dimensioni del secondo rettangolo
     * 
     * @return Vero se i due rettangoli stanno collidendo, altrimenti falso
     */
    bool colliding(sf::Vector2f rect1_pos, sf::Vector2f rect1_size, sf::Vector2f rect2_pos, sf::Vector2f rect2_size)
    {
        if (rect1_pos.x + rect1_size.x >= rect2_pos.x &&
            rect1_pos.x <= rect2_pos.x + rect2_size.x &&
            rect1_pos.y + rect1_size.y >= rect2_pos.y &&
            rect1_pos.y <= rect2_pos.y + rect2_size.y)
            return true;
        return false;
    }

    /** 
     * Calcolo del quadrato della magnitudine di un vettore. 
     * Il vantaggio principale di questa funzione rispetto a 
     * GetMagnitude() è il risparmio del calcolo della 
     * radice quadrata 
     * 
     * @param v Puntatore al vettore
     * 
     * @return Quadrato della magnitudine del vettore
     */
    float getSquareMagnitude(sf::Vector2f *v)
    {
        return (v->x * v->x) + (v->y * v->y);
    }

    /** Calcolo della magnitudine di un vettore
     * 
     * @param v Puntatore al vettore
     * 
     * @return Magnitudine del vettore
     */
    float getMagnitude(sf::Vector2f *v)
    {
        return std::sqrt(getSquareMagnitude(v));
    }

    /** Imposta la magnitudine di un vettore
     * 
     * @param v Puntatore al vettore
     * @param magnitude Nuova magnitudine
     */
    void setMagnitude(sf::Vector2f *v, float magnitude)
    {
        *v = scalare(scalare(*v, magnitude), 1.f/getMagnitude(v));
    }

    /** Restituisce un nuovo vettore con la magnitudine impostata
     * 
     * @param v Vettore di base
     * @param magnitude Nuova magnitudine
     * 
     * @return Nuovo vettore con la magnitudine impostata
     */
    sf::Vector2f setMagnitude(sf::Vector2f v, float magnitude)
    {
        return scalare(scalare(v, magnitude), 1.f/getMagnitude(&v));
    }
}