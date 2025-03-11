#ifndef DIRECTIONS_H
#define DIRECTIONS_H

// North, East, South, West
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, 1, 0, -1};
enum Directions {
    North = 1,
    East  = 2,
    South = 4,
    West  = 8
};

#endif