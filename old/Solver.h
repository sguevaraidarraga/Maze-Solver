#ifndef SOLVER_H
#define SOLVER_H

#pragma once

#include "API.h"
#include <iostream>
#include <queue>
#include <utility>

using std::cerr;
using std::endl;
using std::queue;
using std::pair;

enum Directions {
	North = 1,
	East = 2,
	South = 4,
	West = 8
};

class Solver {
	private:
		static const int N = 16, INF = 1e9;
		int walls[N][N];
		int distance[N][N];
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};

		void initDistances(int x, int y);
		bool inMatrix(int x, int y);
		bool hasWall(int x, int y, int i);
		void bfs(int x, int y);
		void getDirection(Directions &d, int x, int y);
		Directions getRight(Directions d);
		Directions getLeft(Directions d);
		void updateWalls(Directions d, int x, int y);
		void updateIndex(Directions d, int &r, int &c);
		void moveMouse(Directions &d, int &x, int &y);
		bool isGoal(int x, int y);

	public:
		Solver();
		void solve();
		void print(int m[N][N]);
};

#endif