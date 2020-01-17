//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYABLE_H
#define JNP1_6_PROJECT_PLAYABLE_H

#include <memory>
#include <vector>
#include "PlayMode.h"

class Playable {
public:
    virtual void play() const;

};

class Playlist : Playable {
    const std::string name;
public:
    void play() const override;
    void add(Playable element);
    void add(Playable element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(PlayMode mode);

private:
    std::unique_ptr<PlayMode> mode;
    std::vector<std::shared_ptr<Playable>> elements;
};

class Song : Playable {
private:
    std::string artist;
    std::string title;
    std::string other;
    std::string content;
public:
    void play() const override;

};

class Movie : Playable {
private:
    int year;
    std::string title;
    std::string other;
    std::string content;
public:
    void play() const override;

};

#endif //JNP1_6_PROJECT_PLAYABLE_H
