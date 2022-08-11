#include "audio_player.h"
#include <iostream>
#include <fstream>
#include <string>

AudioPlayer::AudioPlayer() {};

void AudioPlayer:: play(AudioPlayer* audioPlayer) {
	
	if (audioPlayer->command != "play") {
		audioPlayer->command = "play";
		std::ifstream playList;
		playList.open("playList.txt");
		while (!playList.eof())
		{
			if (playList.is_open()) {
				playList >> audioPlayer->track >> audioPlayer->authorauthor >> audioPlayer->timeTrack;
				while (audioPlayer->timeTrack != 0) {
					std::cout<< audioPlayer->track << audioPlayer->author << audioPlayer->timeTrack;
					audioPlayer->timeTrack // отнимать секунды
				}
			}
			else
				std::cout << "Playlist not open";
		}
		playList.close();
	}
}