#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class UIPanel {
public:
    sf::RectangleShape Background;
    sf::Text Score;
    sf::Font font;

    UIPanel(int score)
    {
        font.loadFromFile("/Users/levlungin/CLionProjects/Pacman/Amatic-Bold.ttf");

        Background.setFillColor(sf::Color::Black);
        Background.setSize(sf::Vector2f(140.f, 36.f));
        Background.setPosition(sf::Vector2f{550.f, 80.f });

        Score.setString("CURRENT SCORE: " + std::to_string(score));
        Score.setCharacterSize(25);
        Score.setFont(font);
        Score.setStyle(sf::Text::Bold);
        Score.setFillColor(sf::Color::White);
        Score.setPosition(sf::Vector2f(556.f, 82.f));
    }

    void update(int score) { Score.setString("CURRENT SCORE: " + std::to_string(score)); }

    void render(sf::RenderWindow& window)
    {
        window.draw(Background);
        window.draw(Score);
    }
};