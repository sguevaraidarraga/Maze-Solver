#include "Solver.h"

Solver::Solver() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			walls[i][j] = 0;
			distance[i][j] = INF;
		}
	}
}
void Solver::initDistances(int x, int y) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			distance[i][j] = INF;
		}
	}
	distance[x][y] = 0;
}
bool Solver::isInMatrix(int x, int y) {
	return (0 <= x && x < N) && (0 <= y && y < N);
}
bool Solver::hasWall(int x, int y, int i) {
	return walls[x][y] & (1 << i);
}
void Solver::bfs(int x, int y) {
	int cx, cy, nx, ny;
	queue<pair<int, int>> q;
	initDistances(x, y);
	q.push({x, y});
	while(!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			nx = cx + dx[i], ny = cy + dy[i];
			if(isInMatrix(nx, ny) && !hasWall(cx, cy, i) && distance[nx][ny] == INF) {
				distance[nx][ny] = distance[cx][cy] + 1;
				q.push({nx, ny});
			}
		}
	}
}
void Solver::print() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cerr << distance[i][j];
			if(j != N-1) cout << ' ';
		}
		cerr << endl;
	}
}