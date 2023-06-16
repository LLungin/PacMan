#include "Game.h"
#include "Entity.h"
#include "Pacman.h"
#include <iostream>
#include <string>
#include <vector>

const int W = 28;
const int H = 35;

// X - cell
// p - Pacman
// P - Pinky
// I - Inky
// С - Clyde
// B - Blinky
// . - gum
// + - super gum
// = - ghost house

static std::string maze[H] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "Xp....+.....+XX+.....+....+X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X+....+.....+..+.....+....+X",
        "X.XXXX.XX.XXXXXXXX.XX.XXXX.X",
        "X.XXXX.XX.XXXXXXXX.XX.XXXX.X",
        "X+....+XX+..+XX+..+XX+....+X",
        "XXXXXX.XXXXX.XX.XXXXX.XXXXXX",
        "XXXXXX.XXXXX.XX.XXXXX.XXXXXX",
        "XXXXXX.XX+..+..+..+XX.XXXXXX",
        "XXXXXX.XX.XXX==XXX.XX.XXXXXX",
        "XXXXXX.XX.X      X.XX.XXXXXX",
        "+.....+..+X PICB X+..+.....+",
        "XXXXXX.XX.X      X.XX.XXXXXX",
        "XXXXXX.XX.XXXXXXXX.XX.XXXXXX",
        "XXXXXX.XX+........+XX.XXXXXX",
        "XXXXXX.XX.XXXXXXXX.XX.XXXXXX",
        "XXXXXX.XX.XXXXXXXX.XX.XXXXXX",
        "X+....+..+..+XX+..+..+....+X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X+.+XX+..+..+..+..+..+XX+.+X",
        "XXX.XX.XX.XXXXXXXX.XX.XX.XXX",
        "XXX.XX.XX.XXXXXXXX.XX.XX.XXX",
        "X+.+..+XX+..+XX+..+XX+..+.+X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X+....+.....+XX+.....+....+X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX"};

Pinky* P;
Inky* I;
Clyde* C;
Blinky* B;

Game::Game()
{
    width = W;
    height = H;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (maze[i][j] == 'X')
            {
                Wall* wall = new Wall(i * 32.f, j * 32.f, 32.f);
                walls.push_back(wall);
            }

            else if (maze[i][j] == 'p')
                pacman = new Pacman(i * 32.f, j * 32.f);

            else if (maze[i][j] == 'P')
            {
                P = new Pinky(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(P);
            }

            else if (maze[i][j] == 'I')
            {
                I = new Inky(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(I);
            }

            else if (maze[i][j] == 'C')
            {
                C = new Clyde(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(C);
            }

            else if (maze[i][j] == 'B')
            {
                B = new Blinky(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(B);
            }

            else if (maze[i][j] == '.')
            {
                PacGum* PG = new PacGum(i * 32.f, j * 32.f, 4.f);
                objects.push_back(PG);
            }

            else if (maze[i][j] == '+')
            {
                SuperPacGum* SPG = new SuperPacGum(i * 32.f, j * 32.f, 8.f);
                objects.push_back(SPG);
            }
        }
    }
    uiPanel = new UIPanel(score);
}



void Game::updateGame(float elapsedTime, std::vector<Wall*>maze, std::vector<Entity*> objects) {
    pacman->update(elapsedTime, walls, objects);

    P->update(elapsedTime, walls);
    I->update(elapsedTime, walls);
    C->update(elapsedTime, walls);
    B->update(elapsedTime, walls);

    const sf::FloatRect pacmanBounds = pacman->getBounds();

//    for (auto& object : objects)
//    {
//        if (object->isGum)
//        {
//            sf::FloatRect objectBounds = object->getBounds();
//            if (pacmanBounds.intersects(objectBounds))
//            {
//                objects.erase(std::find(objects.begin(), objects.end(), object));
//                score += 10;
//                break;
//            }
//        }
//    }

    bool result = 1;

    while (result)
    {
        result = 0;
        for(int i = 0; i < objects.size(); ++i)
        {
            sf::FloatRect objectBounds = objects[i]->getBounds();
            if (pacmanBounds.intersects(objectBounds))
            {
                result = 1;
                for (int j = i + 1; j < objects.size(); ++j)
                    objects[j - 1] = objects[j];
                objects.pop_back();
                score += 10;
                break;
            }
        }
    }

    uiPanel->update(score);


//    for (auto it = objects.begin(); it != objects.end(); )
//    {
//        Entity* pacGum = *it;
//        sf::FloatRect pacmanBounds = pacman->getBounds();
//        sf::CircleShape pacGumShape(pacGum->size / 2.0f);
//        pacGumShape.setPosition(sf::Vector2f(pacGum->xPos, pacGum->yPos));
//        sf::FloatRect pacGumBounds = pacGumShape.getGlobalBounds();
//        if (pacGumBounds.contains(pacmanBounds.left + pacmanBounds.width / 2.0f, pacmanBounds.top + pacmanBounds.height / 2.0f))
//        {
//            it = objects.erase(it);
//            delete objects;
//        }
//        else
//        {
//            ++it;
//        }
//    }


}// изменения координат объектов

void Game::render(sf::RenderWindow& window)
{
    std::vector<Entity*> Entities = getEntities();
    for (auto& it : Entities)
        it->render(window);

    std::vector<Wall*> Walls = getWalls();
    for (auto& it : Walls)
        it->render(window);

    std::vector<Ghost*> Ghosts = getGhosts();
    for (auto& it : Ghosts)
        it->render(window);

    getPacman().render(window);

    uiPanel->render(window);
}
