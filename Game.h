#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Entity.h"
#include "Ghost.h"
#include "Walls.h"
#include "Uipanel.h"

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
