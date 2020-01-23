#ifndef JNP1_6_PROJECT_PLAYABLE_H
#define JNP1_6_PROJECT_PLAYABLE_H

#include <memory>
#include <vector>
#include <unordered_set>
#include "PlayMode.h"

class Playlist;

class Playable {
public:
    virtual void play() = 0;

    virtual ~Playable() = default;

    virtual void simpleRemove(Playlist*) {};

    virtual void unpinFather(Playlist*) {};
};

class Playlist : public Playable {
public:
    void play() override;

    void add(std::shared_ptr<Playable> element);

    void add(std::shared_ptr<Playable> element, size_t position);

    void add(std::shared_ptr<Playlist> element);

    void add(std::shared_ptr<Playlist> element, size_t position);

    void remove();

    void remove(size_t position);

    void setMode(std::shared_ptr<PlayMode> mode);

    explicit Playlist(const std::string &name);

    ~Playlist() override;

private:
    void positionAdd(std::shared_ptr<Playable> element, size_t position);

    void cycleCheck(std::shared_ptr<Playlist> element);

    bool playlistDFS(Playlist* node, Playlist* toFind);

    void simpleRemove(Playlist* element) override;

    void unpinFather(Playlist* father) override;

    const std::string name;
    std::shared_ptr<PlayMode> mode;
    std::vector<std::shared_ptr<Playable>> elements;
    std::unordered_set<Playlist*> playlistFathers;

};

class Song : public Playable {
private:
    const std::string artist;
    const std::string title;
    const std::string other;
    const std::string content;
public:
    void play() override;

    Song(std::string artist, std::string title,
         std::string other, std::string content);
};

class Movie : public Playable {
private:
    const size_t year;
    const std::string title;
    const std::string other;
    const std::string content;
public:
    void play() override;

    Movie(size_t year, std::string title, std::string other,
          std::string content);

};

#endif //JNP1_6_PROJECT_PLAYABLE_H
