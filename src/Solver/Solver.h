#ifndef SOLVER_H
#define SOLVER_H

#include "../API/API.h"
#include "../Maze/Maze.h"
#include "../Robot/Robot.h"
#include "../Navigator/Navigator.h"
#include <iostream>

class Solver {
    private:
        Maze maze;
        Robot robot;
        Navigator navigator;

    public:
        Solver();
        void solve();
};

#endif