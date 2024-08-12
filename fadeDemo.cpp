#include <SFML/Graphics.hpp>

void fadeTransition(sf::RenderWindow &window, sf::Sprite &currentScreen, sf::Sprite &nextScreen, float duration)
{
    sf::Clock clock;
    sf::RectangleShape fadeOverlay(sf::Vector2f(window.getSize().x, window.getSize().y));

    while (clock.getElapsedTime().asSeconds() < duration)
    {
        float alpha = (clock.getElapsedTime().asSeconds() / duration) * 255;

        fadeOverlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));

        window.clear();
        window.draw(currentScreen);
        window.draw(fadeOverlay);
        window.display();
    }

    clock.restart();

    while (clock.getElapsedTime().asSeconds() < duration)
    {
        float alpha = (1 - (clock.getElapsedTime().asSeconds() / duration)) * 255;

        fadeOverlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));

        window.clear();
        window.draw(nextScreen);
        window.draw(fadeOverlay);
        window.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Smooth Transition Example");

    sf::Texture texture1, texture2;
    texture1.loadFromFile("Images/Board.png");
    texture2.loadFromFile("Images/FoodBoddard.png");

    sf::Sprite currentScreen(texture1);
    sf::Sprite nextScreen(texture2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Display the current screen
        window.clear();
        window.draw(currentScreen);
        window.display();

        // Simulate a screen change after a key press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            fadeTransition(window, currentScreen, nextScreen, 2.0f); // 2.0 seconds fade duration
        }
    }

    return 0;
}
