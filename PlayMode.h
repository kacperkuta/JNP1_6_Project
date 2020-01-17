//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYMODE_H
#define JNP1_6_PROJECT_PLAYMODE_H

#include <memory>

class PlayMode {
public:
    virtual int next() = 0;
};

class Shuffle : PlayMode {
public:
    int next() override;
};

class OddEven : PlayMode {
public:
    int next() override;
};

class Sequence : PlayMode {
public:
    int next() override;
};

class PlayModeFabric {
public:
    static Shuffle createShuffle();
    static OddEven createOddEven();
    static Sequence createSequence();
};


#endif //JNP1_6_PROJECT_PLAYMODE_H
