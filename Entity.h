#pragma once
#include <SFML/Graphics.hpp>

enum struct Direction
{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Entity
{
public:
    virtual sf::FloatRect getBounds() = 0;
    //virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    int xPos;
    int yPos;
    int size;
    bool isGum;
};

class StaticEntity : public Entity {
protected:
    sf::FloatRect bounds;
    sf::CircleShape gums_shape;
    sf::RectangleShape walls_shape;

public:
    sf::FloatRect getBounds() override { return walls_shape.getGlobalBounds(); }
};

class PacGum : public StaticEntity
{
public:
    PacGum(int x, int y, int s)
    {
        gums_shape.setFillColor(sf::Color::White);
        gums_shape.setRadius(s);
        gums_shape.setPosition(sf::Vector2f(x+3*s, y+3*s));
        isGum = true;
    }

    void render(sf::RenderWindow& window) { window.draw(gums_shape); };

    sf::FloatRect getBounds() override { return gums_shape.getGlobalBounds(); }
};

class SuperPacGum : public StaticEntity
{
public:
    SuperPacGum(int x, int y, int s)
    {
        gums_shape.setFillColor(sf::Color::White);
        gums_shape.setRadius(s);
        gums_shape.setPosition(sf::Vector2f(x+s, y+s));
        isGum = true;
    };

    void render(sf::RenderWindow& window) { window.draw(gums_shape); };
    sf::FloatRect getBounds() override { return gums_shape.getGlobalBounds(); }
};

class MovingEntity : public Entity {
protected:
    int speed;
    sf::Vector2i speedVec;
    Direction direction;
    sf::CircleShape shape;
    //etc.
public:
    void unpdatePosition() {}
    void render(sf::RenderWindow& window) {
        window.draw(shape);
    }
    sf::FloatRect getBounds() {
        return shape.getGlobalBounds();
    }
};