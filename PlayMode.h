//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYMODE_H
#define JNP1_6_PROJECT_PLAYMODE_H

#include <memory>
#include <random>

class PlayMode {
public:
    virtual size_t next(size_t size);
};

class Shuffle : PlayMode {
public:
    size_t next(size_t size) override;
    Shuffle(unsigned seed);

private:
    std::default_random_engine generator;
};

class OddEven : PlayMode {
public:
    size_t next(size_t size) override;
    OddEven();
private:
    size_t position;
};

class Sequence : PlayMode {
public:
    size_t next(size_t size) override;
    Sequence();
private:
    size_t position;
};

class PlayModeFabric {
public:
    static Shuffle createShuffle(unsigned seed);
    static OddEven createOddEven();
    static Sequence createSequence();
};


#endif //JNP1_6_PROJECT_PLAYMODE_H
