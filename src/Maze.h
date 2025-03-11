#ifndef MAZE_H
#define MAZE_H

#include "API.h"
#include "Directions.h"
#include <iostream>
#include <queue>
#include <utility>

using std::queue;
using std::pair;

class Maze {
	private:
		static const int N = 16, INF = 1e9;
	    int walls[N][N];
	    int distance[N][N];

	public:
		Maze();
		bool inBounds(int x, int y);
	    bool getWall(int x, int y, int i);
	    void setWall(Directions d, int x, int y);
	    int getDistance(int x, int y);
	    void computeDistances();
};

#endif