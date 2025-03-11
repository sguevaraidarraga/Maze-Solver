#ifndef SOLVER_H
#define SOLVER_H

#include "API.h"
#include "Maze.h"
#include "Robot.h"
#include "Navigator.h"
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