#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include "audio_player.h"
//using namespace std;

int main()
{
	AudioPlayer audioPlayer;
	std::string c; //= "play";
	//std::thread t;
	while (std::cin >> c && c != "exit") {
		std::thread t(&AudioPlayer::play, audioPlayer, c);
		//audioPlayer.play(c);
	}
	//audioPlayer.play(c);
	//cout << "What is bag???";
}
