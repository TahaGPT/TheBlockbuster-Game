#pragma once
#include <iostream>
#include <ctime>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;
class Enemy
{
private:
    RectangleShape enemies;

public:
    Enemy()
    {
        enemies.setSize(Vector2f(30.f, 30.f));
        enemies.setFillColor(Color::White);
    }
    void init(RenderWindow *window)
    {
        enemies.setPosition(Vector2f(float(rand() % int(window->getSize().x - 30.f)), float(rand() % int(window->getSize().y - 30.f))));
    }

    void draw(RenderWindow *window)
    {
        window->draw(enemies);
    }

    bool move(RenderWindow *window)
    {
        enemies.move(2.f, 0);
        if (enemies.getPosition().x >= window->getSize().x - enemies.getSize().x)
        {
            enemies.setPosition(Vector2f(0, enemies.getPosition().y));
            return true;
        }
        else if (enemies.getPosition().y <= 0)
        {
            enemies.setPosition(Vector2f(enemies.getPosition().x, window->getSize().y - enemies.getSize().y));
            return true;
        }

        return false;
    }
};