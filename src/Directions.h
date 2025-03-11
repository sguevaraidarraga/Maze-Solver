#ifndef DIRECTIONS_H
#define DIRECTIONS_H

// Norte, Este, Sur, Oeste
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, 1, 0, -1};
enum Directions {
    North = 1,
    East  = 2,
    South = 4,
    West  = 8
};

Directions getRight(Directions d) {
    Directions ans = North;
    switch(d) {
        case North: ans = East; break;
        case East: ans = South; break;
        case South: ans = West; break;
        case West: ans = North; break;
    }
    return ans;
}
Directions getLeft(Directions d) {
    Directions ans = North;
    switch(d) {
        case North: ans = West; break;
        case West: ans = South; break;
        case South: ans = East; break;
        case East: ans = North; break;
    }
    return ans;
}

#endif