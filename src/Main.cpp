#include "Maze/Maze.h"
#include "Directions/Directions.h"
#include <iostream>

using namespace std;

int main() {
	Maze m;
	m.initDistances();
	m.setWall(7, 7, North);
	m.setWall(7, 7, West);

	m.setWall(7, 8, East);

	m.setWall(8, 7, South);
	m.setWall(8, 7, West);

	m.setWall(8, 8, East);
	m.setWall(8, 8, South);

	cout << "Paredes:" << endl;
	m.printWalls();
	cout << endl << "Distancias:" << endl;
	m.printDistances();
	return 0;
}