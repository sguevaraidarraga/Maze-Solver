#include "API.h"

int API::mazeWidth() {
    cout << "mazeWidth" << endl;
    int response;
    cin >> response;
    return response;
}
int API::mazeHeight() {
    cout << "mazeHeight" << endl;
    int response;
    cin >> response;
    return response;
}
bool API::wallFront() {
    cout << "wallFront" << endl;
    string response;
    cin >> response;
    return response == "true";
}
bool API::wallRight() {
    cout << "wallRight" << endl;
    string response;
    cin >> response;
    return response == "true";
}
bool API::wallLeft() {
    cout << "wallLeft" << endl;
    string response;
    cin >> response;
    return response == "true";
}
void API::moveForward(int distance) {
    cout << "moveForward ";
    // Don't print distance argument unless explicitly specified, for
    // backwards compatibility with older versions of the simulator
    if(distance != 1) {
        cout << distance;
    }
    cout << endl;
    string response;
    cin >> response;
    if(response != "ack") {
        cerr << response << endl;
        throw;
    }
}
void API::turnRight() {
    cout << "turnRight" << endl;
    string ack;
    cin >> ack;
}
void API::turnLeft() {
    cout << "turnLeft" << endl;
    string ack;
    cin >> ack;
}
void API::setWall(int x, int y, char direction) {
    cout << "setWall " << x << " " << y << " " << direction << endl;
}
void API::clearWall(int x, int y, char direction) {
    cout << "clearWall " << x << " " << y << " " << direction << endl;
}
void API::setColor(int x, int y, char color) {
    cout << "setColor " << x << " " << y << " " << color << endl;
}
void API::clearColor(int x, int y) {
    cout << "clearColor " << x << " " << y << endl;
}
void API::clearAllColor() {
    cout << "clearAllColor" << endl;
}
void API::setText(int x, int y, const string &text) {
    cout << "setText " << x << " " << y << " " << text << endl;
}
void API::clearText(int x, int y) {
    cout << "clearText " << x << " " << y << endl;
}
void API::clearAllText() {
    cout << "clearAllText" << endl;
}
bool API::wasReset() {
    cout << "wasReset" << endl;
    string response;
    cin >> response;
    return response == "true";
}
void API::ackReset() {
    cout << "ackReset" << endl;
    string ack;
    cin >> ack;
}