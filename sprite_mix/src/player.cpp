#include "player.h"

//constructor for player class
player::player(float textureScale, sf::Vector2f position)
{
    //set collision rectangle size which will actually be controlled by the keyboard
    rect.setSize(sf::Vector2f(TEXTURE_HEIGHT/4,TEXTURE_WIDTH/4));
    //set the texture scale.. necessary for odd texture resolutions
    rect.setScale(textureScale, textureScale);

    //fill color for collision rectangle, visible only in debug mode if app.draw(player1.rect) is in main()
    rect.setFillColor(sf::Color::Red);
    //set initial rectangle position, also setting the sprite initial position
    rect.setPosition(position);

    //sets sprite scale
    sprite.setScale(textureScale,textureScale);
    //set part of sprite sheet to use when object is created
    sprite.setTextureRect(sf::IntRect(0, TEXTURE_WIDTH*0/4, TEXTURE_HEIGHT/4, TEXTURE_WIDTH/4));
}

void player::update()
{
    //make sprite follow the rectangle, controlling sprite indirectly
    sprite.setPosition(rect.getPosition());
}


//movement control
void player::updateMovement()
{
    //this part is hard coded for a very specific animation sheet.
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            sprite.setTextureRect(sf::IntRect(TEXTURE_HEIGHT*player::animator(ANIMATION_SPEED)/4, TEXTURE_WIDTH*3/4, TEXTURE_HEIGHT/4, TEXTURE_WIDTH/4));
            rect.move(0, NEG*MOVEMENT_SPEED);
            direction=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            sprite.setTextureRect(sf::IntRect(TEXTURE_HEIGHT*player::animator(ANIMATION_SPEED)/4, TEXTURE_WIDTH*2/4, TEXTURE_HEIGHT/4, TEXTURE_WIDTH/4));
            rect.move(NEG*MOVEMENT_SPEED, 0);
            direction=3;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            sprite.setTextureRect(sf::IntRect(TEXTURE_HEIGHT*player::animator(ANIMATION_SPEED)/4, TEXTURE_WIDTH*0/4, TEXTURE_HEIGHT/4, TEXTURE_WIDTH/4));
            rect.move(0, POS*MOVEMENT_SPEED);
            direction=2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            sprite.setTextureRect(sf::IntRect(TEXTURE_HEIGHT*player::animator(ANIMATION_SPEED)/4, TEXTURE_WIDTH*1/4, TEXTURE_HEIGHT/4, TEXTURE_WIDTH/4));
            rect.move(POS*MOVEMENT_SPEED, 0);
            direction=4;
        }
}

int player::animator(float animation_speed)
{
    //make counter increment slowly based on ANIMATION_SPEED
    movement_counter1 = (movement_counter1+ANIMATION_SPEED);
    //take care of counter overflow
    if(movement_counter1 > 32000)
        movement_counter1 = 0.0f;

    /*set to 4 because that is the no of animations in the player sprite sheet, in each line.
    thus cycling through each animation frame after the passage of multiple drawing frames,
    which slows down the animation.*/
    movement_counter2 = ((int)floor(movement_counter1))%4;
    return movement_counter2;
}
