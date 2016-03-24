#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "vaisseaux.hpp"

using namespace std ;
using namespace sf ;

int main()
{
    // Create the main window
    RenderWindow app(sf::VideoMode(1200, 800), "Duel Gravity");


    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("vai.jpg"))
    if (!texture.loadFromFile("vai.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(110, 165/2));
    app.setFramerateLimit(60);

    //Clock1
    sf::Clock clock1;

    //Reine des Neiges
    sf::Music music;

    if (!music.openFromFile("Neige.wav")){//Bug report
    }

    Vaisseaux Vaisseaux1(600,400,0,0,0,0,45);

    int dt;


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {

            // Close window : exit
            if (event.type == Event::Closed)
                app.close();

            if (sf::Keyboard::isKeyPressed(Keyboard::R))
            {
                music.play();
            }
        }

            if (sf::Keyboard::isKeyPressed(Keyboard::Right))
            {
                Vaisseaux1.turnRight();
                texture.loadFromFile("vaid.bmp");
            }

            else if (sf::Keyboard::isKeyPressed(Keyboard::Left))
            {
                Vaisseaux1.turnLeft();
                texture.loadFromFile("vaig.bmp");
            }

            else if (sf::Keyboard::isKeyPressed(Keyboard::Up))
            {
                Vaisseaux1.applyForce(0.0006,0);
                texture.loadFromFile("vaimaa.bmp");
            }
            else if (sf::Keyboard::isKeyPressed(Keyboard::Down))
            {
               Vaisseaux1.applyForce(-0.0003,0);
               texture.loadFromFile("vaimar.bmp");
            }

            else
            {
                texture.loadFromFile("vai.bmp");
            }


        if (Vaisseaux1.getpx() > 1200)
        {
            Vaisseaux1.setpx(0);
        }
        else if (Vaisseaux1.getpx() < 0)
        {
            Vaisseaux1.setpx(1200);
        }
        else if (Vaisseaux1.getpy() > 800)
        {
            Vaisseaux1.setpy(0);
        }
        else if (Vaisseaux1.getpy() < 0)
        {
            Vaisseaux1.setpy(800);
        }

        sf::Time elapsed1 = clock1.getElapsedTime();
        dt = elapsed1.asMilliseconds();
        clock1.restart();

        Vaisseaux1.step(dt);


        sprite.setPosition(sf::Vector2f(Vaisseaux1.getpx(),Vaisseaux1.getpy()));
        sprite.setRotation(Vaisseaux1.getAngle());

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
