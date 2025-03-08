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

class Solver {
	private:
		static const int N = 16, INF = 1e9;

		int walls[N][N];
		int distance[N][N];

		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};

		enum Directions {
			North = 1,
			East = 2,
			South = 4,
			West = 8
		};

		void initDistances(int x, int y);
		bool isInMatrix(int x, int y);
		bool hasWall(int x, int y, int i);

	public:
		Solver();
		void bfs(int x, int y);
		void print();
};

#endif