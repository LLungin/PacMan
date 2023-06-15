#pragma once
#include "Entity.h"

static const float BLINKY_SPEED = 120.f; // pixels per second.
static const float CLYDE_SPEED = 120.f; // pixels per second.
static const float INKY_SPEED = 120.f; // pixels per second.
static const float PINKY_SPEED = 120.f; // pixels per second.



class Ghost : public MovingEntity
{
public:
    Ghost(int x, int y, int size) {};
    Ghost() = default;;
    ~Ghost() = default;;
};

class Pinky : public Ghost
{
public:
    Pinky(int x, int y, int size)
    {
        direction = Direction::NONE;
        shape.setRadius(size);
        shape.setFillColor(sf::Color(255, 192, 203));
        shape.setPosition(sf::Vector2f(x, y));
    };
    Pinky() = default;;
    ~Pinky() = default;;
};

class Inky : public Ghost
{
public:
    Inky(int x, int y, int size)
    {
        direction = Direction::NONE;
        shape.setRadius(size);
        shape.setFillColor(sf::Color::Cyan);
        shape.setPosition(sf::Vector2f(x, y));
    };
    Inky() = default;;
    ~Inky() = default;;
};

class Clyde : public Ghost
{
public:
    Clyde(int x, int y, int size)
    {
        direction = Direction::NONE;
        shape.setRadius(size);
        shape.setFillColor(sf::Color(255, 165, 0));
        shape.setPosition(sf::Vector2f(x, y));
    };
    Clyde() = default;;
    ~Clyde() = default;;
};

class Blinky : public Ghost
{
public:
    Blinky(int x, int y, int size)
    {
        direction = Direction::NONE;
        shape.setRadius(size);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(sf::Vector2f(x, y));
    };
    Blinky() = default;;
    ~Blinky() = default;;
};



// Абстрактный класс ABSTRACTGHOSTFACTORY
class ABSTRACTGHOSTFACTORY {
public:
    virtual Ghost* createGhost(int x, int y, int sixe) = 0;
};

// Классы для призраков
class PINKYFACTORY : public ABSTRACTGHOSTFACTORY {
public:
    Pinky* createGhost(int x, int y, int size) override
    {
        Pinky* ghost = new Pinky(x, y, size);
        return ghost;
    }
};

class INKYFACTORY : public ABSTRACTGHOSTFACTORY {
public:
    Inky* createGhost(int x, int y, int size) override
    {
        Inky* ghost = new Inky(x, y, size);
        return ghost;
    }
};

class CLYDEFACTORY : public ABSTRACTGHOSTFACTORY {
public:
    Clyde* createGhost(int x, int y, int size) override
    {
        Clyde* ghost = new Clyde(x, y, size);
        return ghost;
    }
};

class BLINKYFACTORY : public ABSTRACTGHOSTFACTORY {
public:
    Blinky* createGhost(int x, int y, int size) override
    {
        Blinky* ghost = new Blinky(x, y, size);
        return ghost;
    }
};
