#include <SFML/Graphics.hpp>
#include <math.h>

namespace GameUtils {
    float lerp1d(float a, float b, float k)
    {
        return (1 - k) * a + k * b;
    }

    sf::Vector2f lerp2d(sf::Vector2f a, sf::Vector2f b, float k)
    {
        return sf::Vector2f(lerp1d(a.x, b.x, k), lerp1d(a.y, b.y, k));
    }

    sf::Vector2f scalare(sf::Vector2f v, float s) // v * s
    {
        v.x *= s;
        v.y *= s;
        return v;
    }

    /** Controllo se due numeri sono discordi
     * 
     * @param a Numero a
     * @param b Numero b
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
     * @return vero se i due rettangoli stanno collidendo, altrimenti falso
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

    float getSquareMagnitude(sf::Vector2f *v)
    {
        return (v->x * v->x) + (v->y * v->y);
    }

    float getMagnitude(sf::Vector2f *v)
    {
        return std::sqrt(getSquareMagnitude(v));
    }

    void setMagnitude(sf::Vector2f *v, float magnitude)
    {
        *v = scalare(scalare(*v, magnitude), 1.f/getMagnitude(v));
    }

    sf::Vector2f setMagnitude(sf::Vector2f v, float magnitude)
    {
        return scalare(scalare(v, magnitude), 1.f/getMagnitude(&v));
    }
}