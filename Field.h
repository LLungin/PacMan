#pragma once
#include <SFML/Graphics.hpp>
#include "Walls.h"

enum struct CellCategory
{
    WALL,
    ROAD,
};

struct Cell
{
    CellCategory category;
    sf::RectangleShape bounds;
};

class Field
{
public:
    size_t width = 0;
    size_t height = 0;
    Cell *cells = nullptr; //массив Cell, т.е. прямоугольников с определенной категорией
    Field();
//    void drawField(sf::RenderWindow &window) const;
//    bool checkFieldWallsCollision(const sf::FloatRect &oldBounds, sf::Vector2f &movement);
//    ~Field();
};

sf::Vector2f getPackmanStartPosition();
void initializeField(Field& field);
void drawField(sf::RenderWindow& window, const Field& field);
bool checkFieldWallsCollision(const Field& field, const sf::FloatRect& oldBounds, sf::Vector2f& movement);
void destroyField(Field& field);
