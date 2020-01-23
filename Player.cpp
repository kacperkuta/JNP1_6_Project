#include <memory>
#include <string>
#include "Player.h"
#include "File.h"
#include "Playable.h"
#include "OpeningStrategy.h"

std::shared_ptr<Playable> Player::openFile(const File &file) {
    return file.open(strats());
}

std::shared_ptr<Playlist> Player::createPlaylist(const std::string &name) {
    return std::make_shared<Playlist>(name);
}

void Player::registerStrat(const std::string name, StratCreateMethod strat) {
    strats()[name] = strat;
}

std::unordered_map<std::string, StratCreateMethod>& Player::strats() {
    static std::unordered_map<std::string, StratCreateMethod> str;
    return str;
}

Player::Player() {
    registerStrat("audio", OpenSong::createStrat);
    registerStrat("video", OpenMovie::createStrat);
}