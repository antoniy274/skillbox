#pragma once

#include <iostream>

using namespace std;

struct coordinates {
    int x;
    int y;

    void input() {
        cout << "Enter the coordinates\n";
        cin >> x >> y;
    }

    void print() {
        cout << x << ";" << y << endl;
    }
};

void scalpel(coordinates startingPoint, coordinates endingPoint) {
    cout << "A cut was made between [" << startingPoint.x << ";" << startingPoint.y
        << "] and [" << endingPoint.x << ";" << endingPoint.y << "]\n";
}

void hemostat(coordinates point) {
    cout << "The clamp was made at [" << point.x << ";" << point.y << "]\n";
}

void tweezers(coordinates point) {
    cout << "Tweezers were set at [" << point.x << ";" << point.y << "]\n";
}

void suture(coordinates startingPoint, coordinates endingPoint) {
    cout << "The suture was applied between [" << startingPoint.x << ";" << startingPoint.y
        << "] and [" << endingPoint.x << ";" << endingPoint.y << "]\n";
}

bool isEqual(coordinates a, coordinates b) {
    return a.x == b.x && a.y == b.y;
}