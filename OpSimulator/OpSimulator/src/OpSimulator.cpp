#include "OpSimulator.h"

#include <iostream>
#include <map>

using namespace std;

#define SCALPEL 1
#define HEMOSTAT 2
#define TWEEZERS 3
#define SUTURE 4

#define SCALPEL_NAME "scalpel"
#define HEMOSTAT_NAME "hemostat"
#define TWEEZERS_NAME "tweezers"
#define SUTURE_NAME "suture

int main() {
    string command;

    map <string, int> commands;
    commands[SCALPEL_NAME] = SCALPEL;
    commands[HEMOSTAT_NAME] = HEMOSTAT;
    commands[TWEEZERS_NAME] = TWEEZERS;
    commands[SUTURE_NAME] = SUTURE;

    coordinates startingPoint{};
    coordinates endingPoint{};
    coordinates sutureStartingPoint{};
    coordinates sutureEndingPoint{};


    bool operationIsStarted = false;
    bool operationIsEnded = false;

    while (!operationIsEnded) {

        cout << "Enter a command:\n";
        cin >> command;

        if (command != SCALPEL_NAME && !operationIsStarted) {
            cout << "Operation must started  with \"scalpel\" command!\n";
            continue;
        }

        switch (commands[command]) {
        case SCALPEL: {

            if (operationIsStarted) {
                cout << "The cut was already made\n";
                continue;
            }

            startingPoint.input();
            endingPoint.input();

            scalpel(startingPoint, endingPoint);
            operationIsStarted = true;
            break;
        }
        case HEMOSTAT: {
            coordinates point{};

            point.input();

            hemostat(point);

            break;
        }
        case TWEEZERS: {
            coordinates point{};

            point.input();

            tweezers(point);

            break;
        }
        case SUTURE: {
            sutureStartingPoint.input();
            sutureEndingPoint.input();

            if (isEqual(sutureStartingPoint, startingPoint) && isEqual(sutureEndingPoint, endingPoint)) {
                suture(sutureStartingPoint, sutureEndingPoint);
                operationIsEnded = true;
            }
            else {
                cout << "Coordinates are not equal!\n";
            }

            break;
        }
        default:
            cout << "Wrong command!\n";
            break;
        }
    }

    cout << "Operation is finished";
}
