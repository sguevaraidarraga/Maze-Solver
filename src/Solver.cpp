#include "Solver.h"

Solver::Solver() : robot(15, 0), navigator(maze) {
    maze.computeDistances();
}
void Solver::solve() {
    Directions nextMove;
    while (!maze.getDistance(robot.getX(), robot.getY()) == 0) {
        nextMove = navigator.getNextMove(robot.getDirection(), robot.getX(), robot.getY());
        while (robot.getDirection() != nextMove) {
            if (getRight(robot.getDirection()) == nextMove) {
                robot.turnRight();
            } else {
                robot.turnLeft();
            }
        }
        robot.moveForward();
    }
}