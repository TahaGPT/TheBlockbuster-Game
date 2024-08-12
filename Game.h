#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Enemy.h"
using namespace std;
using namespace sf;
class Game
{
private:
    // private memebrs and functions
    Clock clock;
    RenderWindow *window;
    Texture introScreen;
    Sprite introSprite;
    Sprite gameSprite;
    Event event;
    Sound introSound;
    SoundBuffer introBuffer;
    Music gameMusic;
    bool start = false;
    int maxEnemies = 999999;
    int numEnemies = 0;
    Enemy *enemy = new Enemy[maxEnemies];
    void initVars()
    {
        this->window = nullptr;
        if (!introScreen.loadFromFile("Images/Netflix.png"))
        {
            cerr << "Failed to Load Introduction Screen\n";
        }
        introSprite.setTexture(introScreen);
        introSprite.setPosition(-50.f, -500.f);
        introSprite.setScale(4.0f, 4.0f);
        gameSprite.setColor(Color::Black);

        if (!introBuffer.loadFromFile("Music/Netflix.ogg"))
        {
            cerr << "Error in loading the intro Music\n";
        }
        introSound.setBuffer(introBuffer);
        if (!gameMusic.openFromFile("Music/Doom.ogg"))
        {
            cerr << "Error in Loading the Game Music\n";
        }
    }

    void initWindow()
    {
        this->window = new RenderWindow(VideoMode::getDesktopMode(), "SFML Window", Style::Fullscreen);
        this->window->setFramerateLimit(60);
    }

public:
    // constructor and destructor
    Game()
    {
        this->initVars();
        this->initWindow();
        introSound.setVolume(500);
        introSound.play();
        for (int i = 0; i < maxEnemies; i++)
        {
            enemy[i].init(window);
        }
    }

    void fadeTransition(RenderWindow &window, Sprite &currentScreen, Sprite &nextScreen, float duration)
    {
        Clock clock;
        RectangleShape fadeOverlay(Vector2f(window.getSize().x, window.getSize().y));

        while (clock.getElapsedTime().asSeconds() < duration)
        {
            float alpha = (clock.getElapsedTime().asSeconds() / duration) * 255;

            fadeOverlay.setFillColor(Color(0, 0, 0, static_cast<Uint8>(alpha)));

            window.clear();
            window.draw(currentScreen);
            window.draw(fadeOverlay);
            window.display();
        }

        clock.restart();

        while (clock.getElapsedTime().asSeconds() < duration)
        {
            float alpha = (1 - (clock.getElapsedTime().asSeconds() / duration)) * 255;

            fadeOverlay.setFillColor(Color(0, 0, 0, static_cast<Uint8>(alpha)));

            window.clear();
            window.draw(nextScreen);
            window.draw(fadeOverlay);
            window.display();
        }
    }

    void update()
    {
        events();
        if (start)
        {
            int num = 0;
            for (int i = 0; i <= numEnemies; i++)
            {
                if (enemy[i].move(window))
                {
                    num++;
                }
            }

            while (num > 0 && numEnemies < maxEnemies)
            {
                numEnemies++;
                num--;
            }
        }
    }

    void render()
    {
        if (start)
        {
            window->clear();
            // draw or do something
            for (int i = 0; i <= numEnemies; i++)
            {
                enemy[i].draw(window);
            }
            // display everything on the screen.
            window->display();
        }
        else
        {
            window->clear();
            window->draw(introSprite);
            window->display();
        }
    }

    const bool running() const
    {
        return this->window->isOpen();
    }

    void events()
    {
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
            {
                window->close();
            }

            case Event::KeyPressed:
            {
                if (event.key.code == Keyboard::Escape)
                {
                    window->close();
                }

                else if (event.key.code == Keyboard::Space && !start)
                {
                    fadeTransition(*window, introSprite, gameSprite, 2.0f);
                    start = true;
                    gameMusic.setVolume(50);
                    gameMusic.play();
                }
            }
            }
        }
    }

    virtual ~Game()
    {
        delete window;
        delete[] enemy;
    }
};