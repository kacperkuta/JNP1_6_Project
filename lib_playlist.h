#ifndef JNP1_6_PROJECT_LIB_PLAYLIST_H
#define JNP1_6_PROJECT_LIB_PLAYLIST_H

#include "Player.h"
#include "Playable.h"
#include "File.h"
#include "PlayMode.h"
#include "PlayerException.h"

std::shared_ptr<Sequence> createSequenceMode() {
    return PlayModeFabric::createSequence();
}

std::shared_ptr<Shuffle> createShuffleMode(unsigned seed) {
    return PlayModeFabric::createShuffle(seed);
}

std::shared_ptr<OddEven> createOddEvenMode() {
    return PlayModeFabric::createOddEven();
}

#endif //JNP1_6_PROJECT_LIB_PLAYLIST_H
