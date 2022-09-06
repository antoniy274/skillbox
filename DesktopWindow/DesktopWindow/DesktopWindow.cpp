#include <iostream>
#include "DesktopWindow.h"

using namespace std;

Coordinates DesktopWindow::getCoordinates() {
	return coordinates;
}

int DesktopWindow::getHeight() {
    return height;
}

int DesktopWindow::getWeidth() {
    return width;
}

void DesktopWindow::move() {
    int x;
    int y;
    int newX;
    int newY;
    while (true) {
        cout << "Enter the coordinates\n";
        cin >> x >> y;
        newX = coordinates.x + x;
        newY = coordinates.y + y;
        if (!((newX < 0 || newX > SCREEN_WIDTH - 1) ||
            (newY < 0 || newY > SCREEN_HEIGHT - 1))) {
            break;
        }
        else {
            cout << "Wrong coordinates!\n";
        }
    }
    coordinates.x = newX;
    coordinates.y = newY;
}

void DesktopWindow::resize() {
    do {
        cout << "Enter the width and heigh\n";
        cin >> width >> height;
    } while (width < 0 && height < 0);
}

void Monitor::display(DesktopWindow window) {
    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if ((i >= window.getCoordinates().y && i <= window.getCoordinates().y + window.getHeight() - 1)
                && (j >= window.getCoordinates().x && j <= window.getCoordinates().x + window.getWeidth() - 1)) {
                cout << "1";
            }
            else cout << "0";
        }
        cout << endl;
    }
}