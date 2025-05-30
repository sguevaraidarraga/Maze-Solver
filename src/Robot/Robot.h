#ifndef ROBOT_H
#define ROBOT_H

#include "../API/API.h"
#include "../Directions/Directions.h"

class Robot {
    private:
        int x, y;
        Directions direction;

    public:
        Robot(int startX, int startY);
        void turnLeft();
        void turnRight();
        void moveForward();
        int getX();
        int getY();
        Directions getDirection();
};

#endif