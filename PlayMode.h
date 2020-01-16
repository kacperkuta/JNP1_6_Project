//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYMODE_H
#define JNP1_6_PROJECT_PLAYMODE_H

#include <memory>

class PlayMode {
public:
    virtual  int next() = 0;
};

class Shuffle {
public:
    int next();
};

class OddEven {
public:
    int next();
};

class Sequence {
public:
    int next();
};

class PlayModeFabric {
public:
    static Shuffle createShuffle();
    static OddEven createOddEven();
    static Sequence createSequence();
};


#endif //JNP1_6_PROJECT_PLAYMODE_H
