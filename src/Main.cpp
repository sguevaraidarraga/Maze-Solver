#include "Solver.h"
#include <iostream>

using namespace std;

/*void move(Directions d, int &r, int &c) {
	switch(d) {
		case N: r--; break;
		case E: c++; break;
		case S: r++; break;
		case W: c--; break;
	}
}*/
int main() {
	Solver s;
	s.bfs(15, 0);
	s.print();
	return 0;
}