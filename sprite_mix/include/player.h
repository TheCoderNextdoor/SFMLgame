#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
#include <cmath>
#define MOVEMENT_SPEED 4
#define ANIMATION_SPEED 0.15f
#define POS 1
#define NEG -1
#define TEXTURE_WIDTH 135
#define TEXTURE_HEIGHT 99

class player: public entity
{
    public:
        //these counters are used in animator()
        float movement_counter1 = 0.0f;
        int movement_counter2 = 0;

        int direction = 0; //1 for up 2 for down 3 for left 4 for right
        //player  constructor takes two arguments, texture scale and initial position of spawn
        player(float textureScale, sf::Vector2f position);
        //update position of player sprite based on player rectangle
        void update();
        //move the player in different directions with animations
        void updateMovement();
        //helper function for updateMovement(), animates movement by cycling through the sprite sheet
        int animator(float animation_speed);

    protected:

    private:
};

#endif // PLAYER_H
