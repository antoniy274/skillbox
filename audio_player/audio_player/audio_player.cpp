#include "audio_player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>


AudioPlayer::AudioPlayer() {};

void AudioPlayer:: play(std::string c) {
	setlocale(LC_ALL, "ru");
	if (c == "play") {
		command = "play";
		std::ifstream playList;
		playList.open("C:\\Users\\anton\\Desktop\\skillbox\\audio_player\\audio_player\\playList.txt");

		if (playList.is_open()) {
			while (!playList.eof())
			{
				playList >> track >> author >> std::get_time(&timeTrack, "%M:%S");
				
				time_t currentTime = time(nullptr);
				time_t targetTime = currentTime + timeTrack.tm_min * 60 + timeTrack.tm_sec;

				std::cout << track << ' ' << author << ' ' << targetTime;
				while (currentTime != targetTime) {
					time_t diff = targetTime - currentTime;
					currentTime = time(nullptr);
					if (currentTime + diff != targetTime) {
						int newDiff = targetTime - currentTime;
						//int minutes = newDiff / 60;
						//int seconds = newDiff % 60;
						//std::cout << track << ' ' << author << ' ';
						//std::cout << minutes << ":" << seconds / 10 << seconds % 10 << '\n';
						continue;
					}
				}
			}
		}
		else
			std::cout << "Playlist not open";
		playList.close();
	}
}