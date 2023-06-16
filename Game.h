#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Entity.h"
#include "Ghost.h"
#include "Walls.h"
#include "Uipanel.h"

class Game;

// Абстрактный класс GameState
class GameState {
public:
    virtual ~GameState() {}
    virtual void update() = 0;
    virtual void draw() = 0;
};

// Класс ActiveState
class ActiveState : public GameState {
public:
    ActiveState(Game* game) {};
    virtual void update();
    virtual void draw();

private:
    Game* game;
};

// Класс GameOverState
class GameOverState : public GameState {
public:
    GameOverState(Game* game) {};
    virtual void update();
    virtual void draw(const float dt);

private:
    Game* game;
    sf::Text gameOverText;
};

class Game
{
    int width;
    int height;
    std::vector<Entity*> objects;
    std::vector<Ghost*> ghosts;
    std::vector<Wall*> walls;
    Pacman *pacman;
    int score = 0;
public:
    Game();
    std::vector<Entity*> getEntities() { return objects; };
    std::vector<Ghost*> getGhosts() { return ghosts; };
    std::vector<Wall*> getWalls() { return walls; };
    Pacman getPacman() { return *pacman; };
    UIPanel* uiPanel;
    void updateGame(float elapsedTime, std::vector<Wall*>maze, std::vector<Entity*>objects); // изменения координат объектов
    void render(sf::RenderWindow& window); // отрисовка
    ~Game() = default;
};

