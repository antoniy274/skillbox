#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include "audio_player.h"

using namespace std;

#define PLAY_NAME "play"
#define PAUSE_NAME "pause"
#define NEXT_NAME "next"
#define STOP_NAME "stop"
#define EXIT_NAME "exit"

enum Commands {
    PLAY = 1,
    PAUSE,
    NEXT,
    STOP,
    EXIT
};

int main() {
    srand(time(nullptr));

    map<string, int> commands;
    commands[PLAY_NAME] = Commands::PLAY;
    commands[PAUSE_NAME] = Commands::PAUSE;
    commands[NEXT_NAME] = Commands::NEXT;
    commands[STOP_NAME] = Commands::STOP;
    commands[EXIT_NAME] = Commands::EXIT;

    Player player;

    //vector<Track> tracks;
    string trackNames[3] = { "Master of Puppets", "No Reflection", "Wait and bleed" };
    int durations[3] = { 500, 300, 186 };
    int years[3] = { 1986, 2001, 1999 };
    int mons[3] = { 6, 8, 7 };
    int mday[3] = { 23, 14, 17 };

    for (int i = 0; i < 3; i++) {
        Track newTrack;
        newTrack.setName(trackNames[i]);
        newTrack.setDuration(durations[i]);

        time_t t = time(nullptr);
        tm date1 = *localtime(&t);

        date1.tm_year = years[i];
        date1.tm_mon = mons[i];
        date1.tm_mday = mday[i];

        newTrack.setCreationDate(date1);
        player.addTrack(newTrack);
    }



    while (true) {
        cout << "Enter the command\n";
        string command;
        getline(cin, command);

        switch (commands[command]) {
        case Commands::PLAY: {

            player.play();
            break;
        }
        case Commands::PAUSE: {
            player.pause();
            break;
        }
        case Commands::NEXT: {
            player.next();
            break;
        }
        case Commands::STOP: {
            player.stop();
            break;
        }
        case Commands::EXIT: {
            return 0;
        }
        default:
            cout << "Wrong command\n";
            break;
        }
    }
}