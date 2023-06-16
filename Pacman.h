#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Walls.h"

static const sf::Color PACKMAN_COLOR = sf::Color(255, 216, 0);
static const float PACKMAN_SPEED = 120.f; // pixels per second.
static const float PACKMAN_RADIUS = 15.f; // pixels

class Pacman: public MovingEntity
{
public:
    Pacman(int xPos, int yPos) {
        direction = Direction::NONE;
        shape.setRadius(PACKMAN_RADIUS);
        shape.setFillColor(PACKMAN_COLOR);
        shape.setPosition(sf::Vector2f(xPos, yPos));
    }

    void updatePacmanDirection() {
        direction = Direction::NONE;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction = Direction::UP;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                 || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction = Direction::DOWN;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction = Direction::LEFT;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                 || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction = Direction::RIGHT;
        }
    }

//    sf::Vector2f check1 (sf::Vector2f movement, std::vector<Wall*> walls)
//    {
//        int width = 28;
//        int height = 35;
//        sf::FloatRect pacmanBounds = shape.getGlobalBounds();
//        pacmanBounds.left += movement.x;
//        pacmanBounds.top += movement.y;
//
//        for (auto& cell : walls)
//        {
//            if (cell->isWall)
//            {
//                const sf::FloatRect cellBounds = cell->getBounds();
//                if (cellBounds.intersects(pacmanBounds))
//                    movement = sf::Vector2f(0.f, 0.f);
//                    break;
//
//            }
//        }
//
//        return movement;
//    }

//    std::pair<bool, std::vector<Entity*>::iterator> check2 (sf::Vector2f movement, std::vector<Entity*> objects)
//    {
//        int width = 28;
//        int height = 35;
//        const sf::FloatRect pacmanBounds = shape.getGlobalBounds();
//        bool result = 1;
//        std::vector<Entity*>::iterator gum;
//
//        for (auto& object : objects)
//        {
//            if (object->isGum)
//            {
//                gum = std::find(objects.begin(), objects.end(), object);
//                const sf::FloatRect objectBounds = object->getBounds();
//                if (objectBounds.intersects(pacmanBounds))
//                    result = 0;
//            }
//        }
//
//        std::pair<bool, std::vector<Entity*>::iterator> Pair = std::make_pair(result, gum);
//
//        return Pair;
//    }

    void update(float elapsedTime, std::vector<Wall*> walls, std::vector<Entity*> objects)
    {
        updatePacmanDirection();
        sf::Vector2f movement(0.f, 0.f);
        sf::Vector2f temp;

        switch (direction)
        {
            case Direction::UP:
                temp = {0.f, PACKMAN_SPEED * elapsedTime};
//                result1 = check1(movement-temp, walls);
//
//                if (result1 == 1)
                movement -= temp;
//                else
//                    movement += temp;
                break;
            case Direction::DOWN:
                temp = {0.f, PACKMAN_SPEED * elapsedTime};
//                result1 = check1(movement+temp, walls);
//
//                if (result1 == 1)
                movement += temp;
//                else
//                    movement -= temp;
                break;
            case Direction::LEFT:
                temp = {PACKMAN_SPEED * elapsedTime, 0.f};
//                result1 = check1(movement-temp, walls);
//
//                if (result1 == 1)
                movement -= temp;
//                else
//                    movement += temp;
                break;
            case Direction::RIGHT:
                temp = {PACKMAN_SPEED * elapsedTime, 0.f};
//                result1 = check1(movement+temp, walls);
//
//                if (result1 == 1)
                movement += temp;
//                else
//                    movement -= temp;
                break;
            case Direction::NONE:
                break;
        }
        //  if (checkFieldWallsCollision(field, packmanBounds, movement))
        // {
        //
        //      direction = Direction::NONE;
        // }

//        bool result1 = check1(movement+temp, walls);
//
//        if (result1 == 0)
//        {
//            bool result3 = check1(movement, walls);
//            if (result3 == 1)
//            shape.move(movement);
//        }
//        else

//        const sf::FloatRect pacmanBounds = shape.getGlobalBounds();
        sf::FloatRect futurePacmanBounds = shape.getGlobalBounds();
        futurePacmanBounds.left += movement.x;
        futurePacmanBounds.top += movement.y;

        for (const auto& cell : walls)
        {
            if (cell->isWall)
            {
                const sf::FloatRect cellBounds = cell->getBounds();
                if (cellBounds.intersects(futurePacmanBounds))
                {
                    movement = sf::Vector2f(0.f, 0.f);
                    break;
                }
            }
        }
        shape.move(movement);

//        else if (result1 == 0)
//        {
//            sf::Vector2f Pair (shape.getGlobalBounds().left, shape.getGlobalBounds().top);
//            shape.setPosition(Pair - temp);
//        }

//        bool result = 1;
//        std::vector<Entity*>::iterator gum;
//
//        for (auto& object : objects)
//        {
//            if (object->isGum)
//            {
//                gum = std::find(objects.begin(), objects.end(), object);
//                const sf::FloatRect objectBounds = object->getBounds();
//                if (objectBounds.intersects(pacmanBounds))
//                    result = 0;
//            }
//        }
//
//        if (result == 0)
//            objects.erase(gum);

    }


};
