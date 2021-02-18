#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button() {}

    Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
    {
        text.setString(t);
        text.setColor(textColor);
        text.setCharacterSize(charSize);

        button.setSize(size);
        button.setFillColor(bgColor);
    }

    void setFont(sf::Font &font)
    {
        text.setFont(font);
    }

    void setBackColor(sf::Color color)
    {
        button.setFillColor(color);
    }

    void setTextColor(sf::Color color)
    {
        text.setColor(color);
    }

    void setPosition(sf::Vector2f pos)
    {
        button.setPosition(pos);

        float xPos = (pos.x + button.getLocalBounds().width / 3) - (text.getLocalBounds().width / 2);
        float yPos = (pos.y + button.getLocalBounds().height / 3) - (text.getLocalBounds().height / 2);

        text.setPosition({xPos, yPos});
    }

    void drawTo(sf::RenderWindow &window)
    {
        window.draw(button);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow &window)
    {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float bntPosX = button.getPosition().x;
        float bntPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if (mouseX < btnxPosWidth && mouseX > bntPosX && mouseY < btnyPosHeight && mouseY > bntPosY)
        {
            return true;
        }
        return false;
    }

private:
    sf::RectangleShape button;
    sf::Text text;
};
