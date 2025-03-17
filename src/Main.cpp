#include "Solver/Solver.h"
#include "Directions/Directions.h"
#include <iostream>

using namespace std;

void test(Maze &m) {
	m.setWall(5, 0, East);
	m.setWall(4, 0, North);
	m.setWall(4, 1, East);
	m.setWall(3, 1, North);
	m.setWall(3, 1, East);
	m.setWall(2, 0, East);
	m.setWall(1, 0, East);
	m.setWall(2, 1, East);
	m.setWall(0, 2, South);
	m.setWall(0, 3, South);
	m.setWall(0, 4, South);
	m.setWall(1, 2, South);
	m.setWall(1, 3, South);
	m.setWall(1, 5, South);
	cout << "Paredes:" << endl;
	m.printWalls();
	cout << endl << "Distancias:" << endl;
	m.printDistances();
}
int main() {
	Solver s;
	s.solve();
	return 0;
}