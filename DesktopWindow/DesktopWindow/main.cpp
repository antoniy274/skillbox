#include <iostream>
#include <map>
#include "DesktopWindow.h"

using namespace std;

#define MOVE_NAME "move"
#define RESIZE_NAME "resize"
#define DISPLAY_NAME "display"
#define CLOSE_NAME "close"


enum Commands {
    MOVE = 1,
    RESIZE,
    DISPLAY,
    CLOSE
};

int main()
{

    Monitor screen;
    DesktopWindow window;

    map<string, int> commands;
    commands[MOVE_NAME] = Commands::MOVE;
    commands[RESIZE_NAME] = Commands::RESIZE;
    commands[DISPLAY_NAME] = Commands::DISPLAY;
    commands[CLOSE_NAME] = Commands::CLOSE;


    while (true) {
        string command;

        cout << "Enter the command\n";
        cin >> command;

        switch (commands[command]) {
        case MOVE:
            window.move();
            break;
        case RESIZE:
            window.resize();
            break;
        case DISPLAY:
            screen.display(window);
            break;
        case CLOSE:
            return 0;
        default:
            cout << "Wrong command\n";
            break;
        }
    }
}