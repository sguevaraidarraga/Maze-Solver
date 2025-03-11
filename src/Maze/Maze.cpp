#include "Maze.h"

Maze::Maze() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			walls[i][j] = 0;
			distance[i][j] = INF;
		}
	}
}
bool Maze::inBounds(int x, int y) {
	return (0 <= x && x < N) && (0 <= y && y < N);
}
bool Maze::hasWall(int x, int y, int d) {
	return (walls[x][y] & d) != 0;
}
void Maze::initDistances() {
	int cx, cy, nx, ny, nd;
	queue<pair<int, int>> q;
	q.push({7, 7});
	q.push({7, 8});
	q.push({8, 7});
	q.push({8, 8});
	while(!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			nx = cx + dx[i], ny = cy + dy[i], nd = distance[cx][cy]+1;
			if(inBounds(nx, ny) && distance[nx][ny] == INF) {
				distance[nx][ny] = nd;
				q.push({nx, ny});
			}
		}
	}
}
void Maze::updateDistances(int x, int y) {
	int cx, cy, cd, nx, ny, nd;
	stack<pair<int, int>> s;
	s.push({x, y});
	while(!s.empty()) {
		int cx = s.top().first, cy = s.top().second, cd = distance[cx][cy];
		s.pop();
		for(int i = 0; i < 4; i++) {
			nx = cx + dx[i], ny = cy + dy[i], nd = distance[nx][ny]+1;
			if(inBounds(nx, ny) && !hasWall(cx, cy, (1 << i))) {
				cd = min(cd, nd);
			}
		}
		if(cd != distance[cx][cy]) {
			distance[cx][cy] = cd;
			for(int i = 0; i < 4; i++) {
				nx = cx + dx[i], ny = cy + dy[i];
				if(inBounds(nx, ny) && !hasWall(cx, cy, (1 << i))) {
					s.push({nx, ny});
				}
			}
		}
	}
}
void Maze::setWall(int x, int y, int d) {
    walls[x][y] |= d;
    updateDistances(x, y);
}
int Maze::getDistance(int x, int y) {
	return distance[x][y];
}