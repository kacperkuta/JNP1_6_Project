#include <iostream>
#include "Playable.h"
#include "PlayerException.h"

Playlist::Playlist(const std::string &name)
    : name (name)
    , mode(PlayModeFabric::createSequence())
    {
        mode->usageIncrement();
    }

void Playlist::play() {
    for (int i = 0; i < elements.size(); i++) {
        elements[mode->next(elements.size())]->play();
    }
    mode->reset();
}

void Playlist::add(std::shared_ptr<Playable> element) {
    elements.push_back(element);
}

void Playlist::add(std::shared_ptr<Playlist> element) {
    cycleCheck(element);
    for (const auto& ptr : element->playlistsInside) {
        playlistsInside.insert(ptr);
    }
    playlistsInside.insert(element.get());
    elements.push_back(element);
}

void Playlist::positionAdd(std::shared_ptr<Playable> element, size_t position) {
    if (position <= elements.size()) {
        auto it = elements.begin();
        it += position;
        elements.insert(it, element);
    } else {
        throw IncorrectPosition();
    }
}

void Playlist::cycleCheck(std::shared_ptr<Playlist> element) {
    if (element->playlistsInside.find(this) != element->playlistsInside.end()
            || element.get() == this) {
        throw CyclicPlaylistInsertion();
    }
}

void Playlist::add(std::shared_ptr<Playable> element, size_t position) {
    positionAdd(std::move(element), position);
}

void Playlist::add(std::shared_ptr<Playlist> element, size_t position) {
    cycleCheck(element);
    for (const auto& ptr : element->playlistsInside) {
        playlistsInside.insert(ptr);
    }
    playlistsInside.insert(element.get());
    positionAdd(std::move(element), position);
}

void Playlist::remove() {
    if (!elements.empty()) {
        elements.pop_back();
    } else {
        throw EmptyPlaylistRemove();
    }
}

void Playlist::remove(size_t position) {
    if (elements.size() > position) {
        auto it = elements.begin();
        it += position;
        elements.erase(it);
    } else {
        throw IncorrectPosition();
    }
}

void Playlist::setMode(std::shared_ptr<PlayMode> mode) {
    if (mode->getUsage() > 0) {
        mode = mode->copyOf();
    } else {
        this->mode = mode;
    }
    this->mode->usageIncrement();
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