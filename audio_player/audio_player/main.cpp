#include <iostream>
#include <string>
#include <fstream>
#include "audio_player.h"
//using namespace std;

int main()
{
	AudioPlayer audioPlayer;
	std::string c; //= "play";
	while (std::cin >> c && c != "exit") {
		audioPlayer.play(c);
	}
	audioPlayer.play(c);
	//cout << "What is bag???";
}
