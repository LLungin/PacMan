#include <SFML/Graphics.hpp>
#include "Game.h"

void handleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void update(sf::Clock& clock, Game& game)
{
    const float elapsedTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    game.updateGame(elapsedTime, game.getWalls(), game.getEntities());
}

void render(sf::RenderWindow& window, Game& game)
{
    window.clear();
    game.render(window);
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1120, 896), "PacMan", sf::Style::Close);
    sf::Clock clock;
    Game game;
    while (window.isOpen())
    {
        handleEvents(window);
        update(clock, game);
        render(window, game);
    }
    return 0;
}
