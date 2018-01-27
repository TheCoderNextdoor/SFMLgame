#include "projectile.h"

projectile::projectile()
{
    rect.setSize(sf::Vector2f(10,10));
    rect.setPosition(sf::Vector2f(0,0));
    rect.setFillColor(sf::Color::Blue);
}

void projectile::update()
{
    if(direction==1)
    {
        rect.move(0, -movement_speed);
    }
    if(direction==2)
    {
        rect.move(0, movement_speed);
    }
    if(direction==3)
    {
        rect.move(-movement_speed, 0);
    }
    if(direction==4)
    {
        rect.move(movement_speed, 0);
    }
}

projectile::~projectile()
{

}
