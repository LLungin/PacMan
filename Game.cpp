#include "Game.h"
#include <iostream>
#include <string>

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
                Pinky* P = new Pinky(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(P);
            }

            else if (maze[i][j] == 'I')
            {
                Inky* I = new Inky(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(I);
            }

            else if (maze[i][j] == 'C')
            {
                Clyde* C = new Clyde(i * 32.f, j * 32.f, 16.f);
                ghosts.push_back(C);
            }

            else if (maze[i][j] == 'B')
            {
                Blinky* B = new Blinky(i * 32.f, j * 32.f, 16.f);
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
}

void Game::updateGame(float elapsedTime, std::vector<Wall*>maze) { pacman->update(elapsedTime, walls); }// изменения координат объектов

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
}
