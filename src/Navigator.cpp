#include "Navigator.h"

Navigator::Navigator(Maze &m) : maze(m) {};
Directions Navigator::getNextMove(Directions d, int x, int y) {
    Directions bestDir = d, nd;
    int bestDist = maze.getDistance(x, y), nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i], nd = static_cast<Directions>(1 << i);
        if(maze.inBounds(nx, ny) && !maze.getWall(nd, x, y) && maze.getDistance(nx, ny) < bestDist) {
            bestDist = maze.getDistance(nx, ny);
            bestDir = nd;
        }
    }
    return bestDir;
}