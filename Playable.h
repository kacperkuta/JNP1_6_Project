#ifndef JNP1_6_PROJECT_PLAYABLE_H
#define JNP1_6_PROJECT_PLAYABLE_H

#include <memory>
#include <vector>
#include "PlayMode.h"

class Playable {
public:
    virtual void play() const {};

};

class Playlist : Playable {
public:
    void play() const override;
    void add(std::shared_ptr<Playable> element);
    void add(std::shared_ptr<Playable> element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(PlayMode mode);
    explicit Playlist(const std::string& name) : name(std::string(name)) {};

private:
    PlayMode mode;
    std::vector<std::shared_ptr<Playable>> elements;
    const std::string name;
};

class Song : Playable {
private:
    const std::string artist;
    const std::string title;
    const std::string other;
    const std::string content;
public:
    void play() const override;
    Song(std::string artist,  std::string title,
             std::string other,  std::string content);
};

class Movie : Playable {
private:
    int year;
    const std::string title;
    const std::string other;
    const std::string content;
public:
    void play() const override;
    Movie(int year, std::string title, std::string other, std::string content);

};

#endif //JNP1_6_PROJECT_PLAYABLE_H
