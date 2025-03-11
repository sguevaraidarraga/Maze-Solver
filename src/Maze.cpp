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
bool Maze::getWall(int x, int y, int i) {
	return walls[x][y] & (1 << i);
}
void Maze::setWall(Directions d, int x, int y) {
	walls[x][y] |= d;
}
int Maze::getDistance(int x, int y) {
	return distance[x][y];
}
void Maze::computeDistances() {
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
			if(inBounds(nx, ny) && !getWall(cx, cy, i) && distance[nx][ny] == INF) {
				distance[nx][ny] = nd;
				q.push({nx, ny});
			}
		}
	}
}