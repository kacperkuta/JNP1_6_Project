#include <memory>
#include <string>
#include "Player.h"
#include "File.h"
#include "Playable.h"

std::shared_ptr<Playable> Player::openFile(const File& file) {
  return file.open();
}

std::shared_ptr<Playlist> Player::createPlaylist(const std::string &name) {
  return std::make_shared<Playlist>(name);
}