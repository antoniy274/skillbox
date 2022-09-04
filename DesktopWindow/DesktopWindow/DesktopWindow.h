#pragma once

struct Coordinates {
	int x = 0;
	int y = 0;
};

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 50;

class Monitor {
private:
	char screen[80][50];
	const int screenWidth = SCREEN_WIDTH;
	const int screenHeight = SCREEN_HEIGHT;
public:
	void display(DesktopWindow window);
};

class DesktopWindow {
private:
	Coordinates coordinates;
	int weidth;
	int height;
public:
	Coordinates getCoordinates();
	int getHeight();
	int getWeidth();
	void move();
	void resize();
};