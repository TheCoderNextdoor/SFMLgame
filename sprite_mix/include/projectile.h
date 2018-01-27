#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <entity.h>


class projectile: public entity
{
    public:
        int movement_speed = 10;
        int movement_counter = 0;
        int direction = 0; //1 for up 2 for down 3 for left 4 for right
        projectile();
        void update();
        virtual ~projectile();

    protected:

    private:
};

#endif // PROJECTILE_H
