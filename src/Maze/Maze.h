// https://marsuniversity.github.io/ece387/FloodFill.pdf

#ifndef MAZE_H
#define MAZE_H

#include "../Directions/Directions.h"
#include "../Directions/Directions.h"
#include <vector>
#include <queue>
#include <utility>
#include <stack>
#include <iostream>

using std::vector;
using std::queue;
using std::pair;
using std::stack;
using std::min;
using std::cerr;
using std::endl;

class Maze {
	private:
		static const int N = 16, INF = 1e9;
	    int walls[N][N];
	    int distance[N][N];

	public:
		Maze();
		bool inBounds(int x, int y);
		bool hasWall(int x, int y, int d);
	    void flood(vector<pair<int, int>> &);
	    void updateDistances(int x, int y);
	    void setWall(int x, int y, int d);
	    int getDistance(int x, int y);
		void printWalls();
		void printDistances();
};

#endif