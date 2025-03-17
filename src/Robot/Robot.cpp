#include "Robot.h"

Robot::Robot(int startX, int startY) {
	x = startX;
	y = startY;
	direction = North;
}
void Robot::turnLeft() {
	direction = getLeft(direction);
	API::turnLeft();
}
void Robot::turnRight() {
	direction = getRight(direction);
    API::turnRight();
}
void Robot::moveForward() {
	API::moveForward();
	switch(direction) {
		case North:	x--; break;
		case East:	y++; break;
		case South: x++; break;
		case West:	y--; break;
	}
}
int Robot::getX() {
	return x;
}
int Robot::getY() {
	return y;
}
Directions Robot::getDirection() {
	return direction;
}