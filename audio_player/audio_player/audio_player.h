#pragma once

#include <iostream>
#include <string>

class AudioPlayer{
private:
	std::string track;
	std::string author;
	std::tm timeTrack;
	std::string command;
public:
	AudioPlayer();
	void play(AudioPlayer* audioPlayer);
	void pause(AudioPlayer* audioPlayer);
	void next(AudioPlayer* audioPlayer);
	void stop(AudioPlayer* audioPlayer);
	void exit(AudioPlayer* audioPlayer);
}