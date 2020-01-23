#include <iostream>
#include <cassert>
#include "Playable.h"
#include "PlayerException.h"

Playlist::~Playlist() {
    for (const auto& el : elements) {
        el->unpinFather(this);
    }
}

Playlist::Playlist(const std::string &name)
        : name(name)
        , mode(PlayModeFabric::createSequence()) {
    mode->usageIncrement();
}

void Playlist::play() {
    std::cout << "Playlist[" << name << "]" << std::endl;
    for (size_t i = 0; i < elements.size(); i++) {
        elements[mode->next(elements.size())]->play();
    }
    mode->reset();
}

void Playlist::add(std::shared_ptr<Playable> element) {
    elements.push_back(element);
}

void Playlist::add(std::shared_ptr<Playlist> element) {
    cycleCheck(element);
    element->playlistFathers.insert(this);
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
    if (playlistDFS(this, element.get())) {
        throw CyclicPlaylistInsertion();
    }
}

bool Playlist::playlistDFS(Playlist* node, Playlist* toFind) {
    if (node == toFind)
        return true;
    for (auto playlist : node->playlistFathers) {
        if (playlistDFS(playlist, toFind))
            return true;
    }
    return false;
}

void Playlist::add(std::shared_ptr<Playable> element, size_t position) {
    positionAdd(std::move(element), position);
}

void Playlist::add(std::shared_ptr<Playlist> element, size_t position) {
    cycleCheck(element);
    element->playlistFathers.insert(this);
    positionAdd(std::move(element), position);
}

void Playlist::simpleRemove(Playlist* element) {
    playlistFathers.erase(element);
}

void Playlist::unpinFather(Playlist* father) {
    playlistFathers.erase(father);
}

void Playlist::remove() {
    if (!elements.empty()) {
        elements.back()->simpleRemove(this);
        elements.pop_back();
    } else {
        throw EmptyPlaylistRemove();
    }
}

void Playlist::remove(size_t position) {
    if (elements.size() > position) {
        auto it = elements.begin();
        it += position;
        elements[position]->simpleRemove(this);
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
        : artist(std::move(artist)), title(std::move(title))
        , other(std::move(other)), content(std::move(content)) {}

void Song::play() {
    std::cout << "Song ["
              << artist << ", "
              << title << "]: "
              << content << std::endl;
}

Movie::Movie(const size_t year, std::string title,
             std::string other, std::string content)
        : year(year), title(std::move(title)), other(std::move(other))
        , content(std::move(content)) {}

void Movie::play() {
    std::cout << "Movie ["
              << title << ", "
              << year << "]: "
              << content << std::endl;
}