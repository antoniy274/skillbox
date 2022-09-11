#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "audio_player.h"

std::string Track::getName() {
	return name;
}

tm Track::getCreationDate() {
	return creationDate;
}

int Track::getDuration() {
	return duration;
}

void Track::setName(std::string name) {
	Track::name = name;
}

void Track::setCreationDate(tm date) {
	creationDate.tm_year = date.tm_year;
	creationDate.tm_mon = date.tm_mon;
	creationDate.tm_mday = date.tm_mday;
}

void Track::setDuration(int duration) {
	Track::duration = duration;
}


void Player::addTrack(Track track) {
	tracks[track.getName()] = track;
}

void Player::play() {

	if (!isSongPlaying) {
		std::cout << "Enter the track name\n";
		std::string name;
		std::getline(std::cin, name);
		auto song = tracks.find(name);
		auto end = tracks.end();
		if (song == end) std::cout << "Song not found!\n";
		else {
			tm date = song->second.getCreationDate();
			std::cout << "Now playing: " << name << std::endl <<
				"Duration: " << song->second.getDuration() / 60 << ":" << (song->second.getDuration() % 60) / 10
				<< (song->second.getDuration() % 60) % 10 << std::endl
				<< "Creation date: " << date.tm_year << "/" << date.tm_mon + 1 << "/" << date.tm_mday << std::endl;
			isSongPlaying = true;
			isSongPaused = false;
			currentTrack = &song->second;
		}
	}
}

void Player::pause() {
	if (isSongPlaying && !isSongPaused) {
		isSongPaused = true;
		isSongPlaying = false;
		std::cout << currentTrack->getName() << " is paused\n";
	}
}

void Player::next() {
	std::vector<std::string> songsNames;
	for (auto& i : tracks) {
		songsNames.push_back(i.first);
	}

	int currentTrackNumber = -1;
	if (currentTrack != nullptr) {
		for (int i = 0; i < songsNames.size(); i++) {
			if (currentTrack->getName() == songsNames[i]) {
				currentTrackNumber = i;
				break;
			}
		}
	}

	int randTrackNumber;

	do {
		randTrackNumber = rand() % songsNames.size();
	} while (randTrackNumber == currentTrackNumber);

	auto nextTrack = tracks.find(songsNames[randTrackNumber]);
	currentTrack = &nextTrack->second;

	std::cout << "Now playing: " << currentTrack->getName() << std::endl;
	isSongPlaying = true;
	isSongPaused = false;
}

void Player::stop() {
	if (isSongPlaying || isSongPaused) {
		currentTrack = nullptr;
		isSongPlaying = false;
		isSongPaused = false;
		//delete currentTrack;
	}
}