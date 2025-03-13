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

inline int directionToIndex(int d) {
    int ans;
    switch(d) {
        case North: ans = 0; break;
        case East: ans = 1; break;
        case South: ans = 2; break;
        case West: ans = 3; break;
    }
    return ans;
}
inline int oppositeDirection(int d) {
    int ans = 0;
    switch(d) {
        case North: ans = South; break;
        case East: ans = West; break;
        case South: ans = North; break;
        case West: ans = East; break;
    }
    return ans;
}

#endif