#pragma once
#include "Entity.h"
#include "Pacman.h"

static const float GHOST_SPEED = 100.f; // pixels per second.

class GhostState;
class HouseModeState;
class ChaseModeState;
class ScatterModeState;
class FrightenedModeState;
class EatenModeState;

class Ghost : public MovingEntity
{

    GhostState* currentState;
    HouseModeState* houseMode;
    ChaseModeState* chaseMode;
    ScatterModeState* scatterMode;
    FrightenedModeState* frightenedMode;
    EatenModeState* eatenMode;

    bool isChasing;

public:
    Ghost(int x, int y, int size);
    Ghost() = default;;
    ~Ghost();
    void setState(GhostState* newState) {
        currentState = newState;
    };
//    void setPacman(Pacman* pacman) {};
    bool is_Chasing () const { return isChasing; };
//    void setChasingStatus (bool isChasing);
//    void setDangerousStatus (bool isDangerous);

    HouseModeState* getHouseMode() { return houseMode; };
    ChaseModeState* getChaseMode () { return chaseMode; };
    ScatterModeState* getScatterMode () { return scatterMode; };
    FrightenedModeState* getFrightenedMode () { return frightenedMode; };
    EatenModeState* getEatenMode () { return eatenMode; };
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

class GhostState {
protected:
    Ghost* ghost;

public:
    GhostState(Ghost* ghost) : ghost(ghost) {}

    virtual void superPacGumEaten() = 0;
    virtual void timerModeOver() = 0;
    virtual void timerFrightenedMode() = 0;
    virtual void eaten() = 0;
    virtual void outsideHouse() = 0;
    virtual void insideHouse() = 0;
    virtual void computeNextDir() = 0;
    virtual sf::Vector2f getTargetPosition() = 0;
};

class HouseModeState : public GhostState {
public:
    HouseModeState(Ghost* ghost) : GhostState(ghost) {}

    void superPacGumEaten() override {}

    void timerModeOver() override {}

    void timerFrightenedMode() override {}

    void eaten() override {}

    void outsideHouse() ;

    void insideHouse() override {}

    void computeNextDir() override {}

    sf::Vector2f getTargetPosition() override { return sf::Vector2f{0, 0}; } // Возвращаем позицию дома призраков
};

class ChaseModeState : public GhostState {
public:
    ChaseModeState(Ghost* ghost) : GhostState(ghost) {}

    void superPacGumEaten();

    void timerModeOver();

    void timerFrightenedMode() override {}

    void eaten() override {}

    void outsideHouse() override {}

    void insideHouse() override {}

    void computeNextDir() override {}

    sf::Vector2f getTargetPosition() override {}
};


class ScatterModeState : public GhostState {
public:
    ScatterModeState(Ghost* ghost) : GhostState(ghost) {};
    void superPacGumEaten() ;

    void timerModeOver() ;

    void timerFrightenedMode() override {}

    void eaten() override {}

    void outsideHouse() override {}

    void insideHouse() override {}

    void computeNextDir() override {}

    sf::Vector2f getTargetPosition() override {}
};

class FrightenedModeState : public GhostState {
public:
    FrightenedModeState(Ghost* ghost) : GhostState(ghost) {}

    void superPacGumEaten() override {}

    void timerModeOver() override {}

    void timerFrightenedMode() ;

    void eaten() ;

    void outsideHouse() override {}

    void insideHouse() override {}

    void computeNextDir() override {}

    sf::Vector2f getTargetPosition() override {}
};

class EatenModeState : public GhostState {
public:
    EatenModeState(Ghost* ghost) : GhostState(ghost) {}
    void superPacGumEaten() override {}

    void timerModeOver() override {}

    void timerFrightenedMode() override {}

    void eaten() override {}

    void outsideHouse() override {}

    void insideHouse() ;

    void computeNextDir() override {}

    sf::Vector2f getTargetPosition() override {}
};



// Абстрактный класс ABSTRACTGHOSTFACTORY
class ABSTRACTGHOSTFACTORY {
public:
    virtual Ghost* createGhost(int x, int y, int size) = 0;
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

