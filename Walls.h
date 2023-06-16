#pragma once
#include "Entity.h"
#include "iostream"

class Wall: public StaticEntity
{
public:
    Wall(int x, int y, int s)
    {
        xPos = x;
        yPos = y;
        size = s;
        isWall = true;
    }

    void render(sf::RenderWindow& window) override
    {
        walls_shape.setFillColor(sf::Color(52, 93, 199));
        walls_shape.setSize(sf::Vector2f(size, size));
        walls_shape.setPosition(sf::Vector2f(xPos, yPos));
        window.draw(walls_shape);
    }

    bool isWall;
};
