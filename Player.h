//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYER_H
#define JNP1_6_PROJECT_PLAYER_H

#include "Playable.h"

class Player {

public:
    Playable openFile(const std::string& file);
    Playlist createPlaylist(const std::string& name);

};


#endif //JNP1_6_PROJECT_PLAYER_H
