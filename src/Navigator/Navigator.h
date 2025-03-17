#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "../Maze/Maze.h"
#include "../Robot/Robot.h"

class Navigator {
    private:
        Maze &maze;

    public:
        Navigator(Maze &m);
        Directions getNextMove(Directions d, int x, int y);
};

#endif