//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYABLE_H
#define JNP1_6_PROJECT_PLAYABLE_H

#include <memory>
#include "PlayMode.h"

class Playable {
public:
    virtual void play() const;

};

class Playlist : Playable {
public:
    void play();

private:
    std::unique_ptr<PlayMode> myPlayMode;
};

class Song : Playable {
public:
    void play();
};

class Movie : Playable {
public:
    void play();
};

#endif //JNP1_6_PROJECT_PLAYABLE_H
