#pragma once

class Track {
    std::string name;
    tm creationDate;
    int duration = 0;

public:
    std::string getName();
    tm getCreationDate();
    int getDuration();
    void setName(std::string name);
    void setCreationDate(tm date);
    void setDuration(int duration);
};

class Player {

    std::map<std::string, Track> tracks;
    Track* currentTrack;
    bool isSongPlaying = false;
    bool isSongPaused = false;

public:

    void addTrack(Track track);
    void play();
    void pause();
    void next();
    void stop();
};