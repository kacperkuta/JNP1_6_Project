//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYER_H
#define JNP1_6_PROJECT_PLAYER_H

#include "Playable.h"
#include "File.h"

class Player {

public:
    std::shared_ptr<Playable> openFile(const File& file);
    std::shared_ptr<Playlist> createPlaylist(std::string name);
};


#endif //JNP1_6_PROJECT_PLAYER_H
