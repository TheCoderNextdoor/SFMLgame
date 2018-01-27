#include <SFML/Graphics.hpp>
#include <iostream>
#include <player.h>
#include <entity.h>
#include <projectile.h>
#include <vector>

int main()
{
    // Create the main window & set frame rate
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);
    app.setFramerateLimit(60);

    //Create a background color rectangle
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color(200, 200, 30, 255));
    rect.setSize(sf::Vector2f(800, 600));
    rect.setPosition(sf::Vector2f(0,0));

    // Load a sprite for player object
    sf::Texture texture;
    if (!texture.loadFromFile("spritesheet_assets1.png"))
        return EXIT_FAILURE;

    //create a player object
    class player Player1(1.0f, sf::Vector2f(400,300));
    Player1.sprite.setTexture(texture);

    //create a projectile
    class projectile Projectile1;
    //create a vector to store the spawned projectiles
    std::vector<projectile>::const_iterator itr;
    std::vector<projectile> projectileVector;



	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        //draw background
        app.draw(rect);

        //fires projectile
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - Projectile1.rect.getSize().x/2,
                                         Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - Projectile1.rect.getSize().y/2);
            Projectile1.direction= Player1.direction;
            projectileVector.push_back(Projectile1);
        }

        //displays all projectiles
        int counter =0;
        for(itr = projectileVector.begin(); itr!=projectileVector.end(); itr++)
        {
            projectileVector[counter].update();
            app.draw(projectileVector[counter].rect);
            counter++;
            std::cout<<counter<<std::endl;
        }




        //update player to follow Player.rect
        Player1.update();
        //update movement
        Player1.updateMovement();
        //draw player
        app.draw(Player1.sprite);
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
