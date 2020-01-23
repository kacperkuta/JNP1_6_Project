//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYER_H
#define JNP1_6_PROJECT_PLAYER_H

#include <memory>
#include <string>
#include "Playable.h"
#include "File.h"


class Player {

public:
    std::shared_ptr<Playable> openFile(const File& file);
    std::shared_ptr<Playlist> createPlaylist(const std::string& name);
    Player();

private:
    void registerStrat(std::string name, StratCreateMethod strat);

    std::unordered_map<std::string, StratCreateMethod>& strats();
};


#endif //JNP1_6_PROJECT_PLAYER_H
