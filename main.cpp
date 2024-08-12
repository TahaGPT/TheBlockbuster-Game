#include <iostream>
#include <ctime>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
using namespace std;
using namespace sf;
int main()
{
    srand(time(NULL));
    // RenderWindow window(VideoMode::getDesktopMode(), "Milestone to Gaming", Style::Fullscreen);
    // Event event;
    Game game;
    while (game.running())
    {
        game.update();
        game.render();
        // Handling Events
        // while (window.pollEvent(event))
        // {
        //     switch (event.type)
        //     {
        //     case Event::Closed:
        //     {
        //         window.close();
        //     }

        //     case Event::KeyPressed:
        //     {
        //         if (event.key.code == Keyboard::Escape)
        //         {
        //             window.close();
        //         }
        //     }
        //     }
        // }

        // Handling the updation

        // outputting the results
            }   
}