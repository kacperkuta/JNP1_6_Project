#include "Playable.h"
#include <iostream>

Playlist::Playlist(const std::string &name)
    : name (name)
    , mode(std::move(PlayModeFabric::createSequence())){}

void Playlist::play() {
    for (int i = 0; i < elements.size(); i++) {
        elements[mode.next(elements.size())]->play();
    }
    mode.reset();
}

void Playlist::add(std::shared_ptr<Playable> element) {
    elements.push_back(element);
}

void Playlist::add(std::shared_ptr<Playable> element, size_t position) {
    if (position <= elements.size()) {
        auto it = elements.begin();
        it += position;
        elements.insert(it, element);
    } else {
        //TODO
        //wyjątek
    }
}

void Playlist::remove() {
    if (!elements.empty()) {
        elements.pop_back();
    } else {
        //TODO
        //wyjątek
    }
}

void Playlist::remove(size_t position) {
    if (elements.size() > position) {
        auto it = elements.begin();
        it += position;
        elements.erase(it);
    } else {
        //TODO
        //wyjątek
    }
}

void Playlist::setMode(PlayMode mode) {
    this->mode = std::move(mode);
}

Song::Song(std::string artist, std::string title,
           std::string other, std::string content)
           : artist(std::move(artist))
           , title(std::move(title))
           , other(std::move(other))
           , content(std::move(content)) {}

void Song::play() {
    std::cout << "Song ["
              << artist << ", "
              << title << "]: "
              << content << std::endl;
}

Movie::Movie(int year, std::string title,
        std::string other, std::string content)
        : year(year)
        , title(std::move(title))
        , other(std::move(other))
        , content(std::move(other)) {}

void Movie::play() {
    std::cout << "Movie ["
              << title << ", "
              << year << "]: "
              << content << std::endl;
}