#include <iostream>
#include <map>
#include "..\include\gpu.h"
#include "..\include\ram.h"
#include "..\include\kbd.h"
#include "..\include\cpu.h"
#include "..\include\disk.h"
using namespace std;

#define SUM 1
#define SAVE 2
#define LOAD 3
#define INPUT 4
#define DISPLAY 5
#define EXIT 6

#define SUM_NAME "sum"
#define SAVE_NAME "save"
#define LOAD_NAME "load"
#define INPUT_NAME "input"
#define DISPLAY_NAME "display"
#define EXIT_NAME "exit"

int main() {
    map<string, int> commands;
    commands[SUM_NAME] = SUM;
    commands[SAVE_NAME] = SAVE;
    commands[LOAD_NAME] = LOAD;
    commands[INPUT_NAME] = INPUT;
    commands[DISPLAY_NAME] = DISPLAY;
    commands[EXIT_NAME] = EXIT;

//    cout << "HI" << endl;
//    std::vector<int> v = read();
//    input();
//
//    int count = compute();
//    cout << count << endl;
//
//    display();
//
//    save(v);
//
//    vector<int> test = { 1, 2, 3, 4, 6, 8, 9, 10};
//    write(test);
//
//    load();
//
//    display();

    while(true) {
        cout << "Enter a command\n";
        string command;
        cin >> command;

        switch (commands[command]) {
            case SUM:
                compute();
                break;
            case SAVE:
                save();
                break;
            case LOAD:
                load();
                break;
            case INPUT:
                input();
                break;
            case DISPLAY:
                display();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Wrong operation\n";
                break;
        }
    }
}
