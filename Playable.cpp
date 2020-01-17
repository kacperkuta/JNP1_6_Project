#include "Playable.h"
#include <iostream>

void Playlist::play() const {
    for (const std::shared_ptr<Playable>& el : elements) {
        el->play();
    }
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

void Song::play() const {
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

void Movie::play() const {
    std::cout << "Movie ["
              << title << ", "
              << year << "]: "
              << content << std::endl;
}