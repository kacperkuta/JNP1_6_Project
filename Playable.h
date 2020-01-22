#ifndef JNP1_6_PROJECT_PLAYABLE_H
#define JNP1_6_PROJECT_PLAYABLE_H

#include <memory>
#include <vector>
#include "PlayMode.h"

class Playable {
public:
    virtual void play() {};
    virtual ~Playable() = default;

};

class Playlist : public Playable {
public:
    void play() override;
    void add(std::shared_ptr<Playable> element);
    void add(std::shared_ptr<Playable> element, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(std::shared_ptr<PlayMode> mode);

    explicit Playlist(const std::string& name);
    ~Playlist() override = default;

private:
    const std::string name;
    std::shared_ptr<PlayMode> mode;
    std::vector<std::shared_ptr<Playable>> elements;
};

class Song : public Playable {
private:
    const std::string artist;
    const std::string title;
    const std::string other;
    const std::string content;
public:
    void play() override;
    Song(std::string artist,  std::string title,
             std::string other,  std::string content);
    ~Song() override = default;
};

class Movie : public Playable {
private:
    std::string year;
    const std::string title;
    const std::string other;
    const std::string content;
public:
    void play() override;
    Movie(std::string year, std::string title, std::string other, std::string content);
    ~Movie() override = default;

};

#endif //JNP1_6_PROJECT_PLAYABLE_H
