// https://github.com/mackorone/mms/tree/main

#ifndef API_H
#define API_H

#include <string>
#include <cstdlib>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class API {
    public:
        static int getMazeWidth();
        static int getMazeHeight();
        static bool getWallFront();
        static bool getWallRight();
        static bool getWallLeft();
        static void moveForward(int distance = 1);
        static void turnRight();
        static void turnLeft();
        static void setWall(int x, int y, char direction);
        static void clearWall(int x, int y, char direction);
        static void setColor(int x, int y, char color);
        static void clearColor(int x, int y);
        static void clearAllColor();
        static void setText(int x, int y, const std::string& text);
        static void clearText(int x, int y);
        static void clearAllText();
        static bool wasReset();
        static void ackReset();
};

#endif