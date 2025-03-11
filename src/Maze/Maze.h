#ifndef MAZE_H
#define MAZE_H

#include "Directions.h"
#include <queue>
#include <utility>
#include <stack>

using std::queue;
using std::pair;
using std::stack;

class Maze {
	private:
		static const int N = 16, INF = 1e9;
	    int walls[N][N];
	    int distance[N][N];

	public:
		Maze();
		bool inBounds(int x, int y);
		bool hasWall(int x, int y, int d);
	    void initDistances();
	    void updateDistances(int x, int y);
	    void setWall(int x, int y, int d);
	    int getDistance(int x, int y);
};

#endif