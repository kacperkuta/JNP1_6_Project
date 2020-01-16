//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYMODE_H
#define JNP1_6_PROJECT_PLAYMODE_H

#include "Playable.h"
#include <memory>

class PlayMode {
public:
    virtual void play(const Playlist& playlist) = 0;
};

class Shuffle {
public:
    void play(const Playlist& playlist);
};

class OddEven {
public:
    void play(const Playlist& playlist);
};

class Sequence {
public:
    void play(const Playlist& playlist);
};

class PlayModeFabric {
public:
    std::unique_ptr<Shuffle> createShuffle {
        return std::make_unique<Shuffle>();
    }
};


#endif //JNP1_6_PROJECT_PLAYMODE_H
