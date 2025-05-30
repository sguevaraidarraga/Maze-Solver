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
void Maze::flood(vector<pair<int, int>> &goals) {
	int cx, cy, nx, ny, nd;
	queue<pair<int, int>> q;
	for(int i = 0; i < goals.size(); i++) {
		distance[goals[i].first][goals[i].second] = 0;
		q.push({goals[i].first, goals[i].second});
	}
	q.push({7, 7});
	q.push({7, 8});
	q.push({8, 7});
	q.push({8, 8});
	while(!q.empty()) {
		cx = q.front().first, cy = q.front().second;
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
	int cx, cy, md, nx, ny;
    stack<pair<int, int>> s;
    s.push({x, y});
    while(!s.empty()) {
		cx = s.top().first, cy = s.top().second;
		s.pop();
    	md = INF;
		for(int i = 0; i < 4; i++) {
			nx = cx + dx[i], ny = cy + dy[i];
			if(inBounds(nx, ny) && !hasWall(cx, cy, 1 << i)) {
				md = min(md, distance[nx][ny]);
			}
		}
		if(distance[cx][cy]-1 != md) {
			distance[cx][cy] = md+1;
			for(int i = 0; i < 4; i++) {
				nx = cx + dx[i], ny = cy + dy[i];
				if(inBounds(nx, ny) && distance[nx][ny] != 0) {
					s.push({nx, ny});
				}
			}
		}
    }
}
void Maze::setWall(int x, int y, int d) {
    int idx = directionToIndex(d), nx = x + dx[idx], ny = y + dy[idx];
    walls[x][y] |= d;
    if(inBounds(nx, ny)) {
        walls[nx][ny] |= oppositeDirection(d);
    }
    updateDistances(x, y);
}
int Maze::getDistance(int x, int y) {
	return distance[x][y];
}
void Maze::printWalls() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cerr << walls[i][j];
			if(j != N-1) {
				cerr << ' ';
			}
		}
		cerr << std::endl;
	}
}
void Maze::printDistances() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cerr << distance[i][j];
			if(j != N-1) {
				cerr << ' ';
			}
		}
		cerr << std::endl;
	}
}