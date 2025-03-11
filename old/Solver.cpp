#include "Solver.h"

Solver::Solver() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			walls[i][j] = 0;
			distance[i][j] = INF;
		}
	}
}
bool Solver::inMatrix(int x, int y) {
	return (0 <= x && x < N) && (0 <= y && y < N);
}
bool Solver::hasWall(int x, int y, int i) {
	return walls[x][y] & (1 << i);
}
void Solver::bfs(int x, int y) {
	int cx, cy, nx, ny, nd;
	queue<pair<int, int>> q;

	q.push({7, 7});
	q.push({7, 8});
	q.push({8, 7});
	q.push({8, 8});

	//q.push({x, y});
	while(!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			nx = cx + dx[i], ny = cy + dy[i], nd = distance[cx][cy]+1;
			if(inMatrix(nx, ny) && !hasWall(cx, cy, i) && distance[nx][ny] == INF) {
				distance[nx][ny] = nd;
				q.push({nx, ny});
			}
		}
	}
}
void Solver::getDirection(Directions &d, int x, int y) {
	Directions ans = d, nd;
	int dist = distance[x][y], nx, ny;
	for(int i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i], nd = static_cast<Directions>(1 << i);
		if(inMatrix(nx, ny) && !hasWall(x, y, i) && distance[nx][ny] < dist) {
			dist = distance[nx][ny];
			ans = nd;
		}
	}
	while (d != ans) {
        if (getRight(d) == ans) {
            d = getRight(d);
            API::turnRight();
        } else {
            d = getLeft(d);
            API::turnLeft();
        }
    }
}
Directions Solver::getRight(Directions d) {
	Directions ans = d;
    switch(d) {
        case North: ans = East;	break;
        case East: ans = South;	break;
        case South: ans = West; break;
        case West: ans = North; break;
    }
    return ans;
}
Directions Solver::getLeft(Directions d) {
	Directions ans = d;
    switch(d) {
        case North: ans = West;	break;
        case West: ans = South;	break;
        case South: ans = East;	break;
        case East: ans = North;	break;
    }
    return ans;
}
void Solver::updateWalls(Directions d, int x, int y) {
	int prev = walls[x][y];
	if(API::getWallFront()) {
	    walls[x][y] |= d;
	}
	if(API::getWallRight()) {
		walls[x][y] |= getRight(d);
	}
	if(API::getWallLeft()) {
		walls[x][y] |= getLeft(d);
	}
	if(walls[x][y] != prev) {
		bfs(x, y);
	}
}
void Solver::updateIndex(Directions d, int &r, int &c) {
	switch(d) {
		case North:	r--; break;
		case East:	c++; break;
		case South: r++; break;
		case West:	c--; break;
	}
}
void Solver::moveMouse(Directions &d, int &x, int &y) {
	updateWalls(d, x, y);
	getDirection(d, x, y);
	API::moveForward();
	updateIndex(d, x, y);
}
bool Solver::isGoal(int x, int y) {
	return (x == 7 && y == 7) || (x == 7 && y == 8) || (x == 8 && y == 7) || (x == 8 && y == 8);
}
void Solver::solve() {
	int x = 15, y = 0;
	Directions d = North;
	//distance[x][y] = 0;
	distance[7][7] = 0;
	distance[7][8] = 0;
	distance[8][7] = 0;
	distance[8][8] = 0;
	bfs(x, y);
	while(!isGoal(x, y)) {
		moveMouse(d, x, y);
		print(walls);
	}
}
void Solver::print(int m[N][N]) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cerr << m[i][j];
			if(j != N-1) cout << ' ';
		}
		cerr << endl;
	}
	cerr << endl;
}