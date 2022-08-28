#pragma once

#include <iostream>
#include <string>

class AudioPlayer {
private:
	std::string track;
	std::string author;
	std::tm timeTrack;
	std::string command;
public:
	AudioPlayer();
	void play(std::string c);
	void pause(std::string c);
	void next(std::string c);
	void stop(std::string c);
	void exit(std::string c);
};