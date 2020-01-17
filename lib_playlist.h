//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_LIB_PLAYLIST_H
#define JNP1_6_PROJECT_LIB_PLAYLIST_H

#include "Player.h"
#include "Playable.h"
#include "File.h"
#include "PlayMode.h"
#include "PlayerException.h"

Sequence createSequenceMode() {
    return PlayModeFabric::createSequence();
}
Shuffle createShuffleMode(unsigned seed) {
    return PlayModeFabric::createShuffle(seed);
}
OddEven createOddEvenMode() {
    return PlayModeFabric::createOddEven();
}

#endif //JNP1_6_PROJECT_LIB_PLAYLIST_H
