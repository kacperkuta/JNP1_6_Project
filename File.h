//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_FILE_H
#define JNP1_6_PROJECT_FILE_H

#include "Playable.h"

class OpeningStrategy {
    virtual Playable open();
};

class OpenSong : OpeningStrategy {
    Playable open() override;
};

class OpenMovie : OpeningStrategy {
    Playable open() override;
};

class File {
    std::string desc;
    OpeningStrategy strategy;
};



#endif //JNP1_6_PROJECT_FILE_H
