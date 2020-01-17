//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYMODE_H
#define JNP1_6_PROJECT_PLAYMODE_H

#include <memory>
#include <random>

/**
 * @brief Playlist playmode base class
 */
class PlayMode {
public:
    /**
     * @brief Gives next @ref Playable to play.
     * @param size Size of playlist.
     * @return Next @ref Playable to play.
     */
    virtual size_t next(size_t size);
    virtual void reset() {};
};


/**
 * @brief Suffle playmode derived class
 */
class Shuffle : public PlayMode {
public:
    size_t next(size_t size) override;
    void reset() override;
    explicit Shuffle(unsigned seed);

private:
    unsigned seed;
    std::default_random_engine generator;
};

/**
 * @brief OddEven playmode derived class
 */
class OddEven : public PlayMode {
public:
    size_t next(size_t size) override;
    void reset() override;
    OddEven();
private:
    size_t position;
};

/**
 * @brief Sequence playmode derived class
 */
class Sequence : public PlayMode {
public:
    size_t next(size_t size) override;
    void reset() override;
    Sequence();
private:
    size_t position;
};

/**
 * @brief Fabric of playmodes.
 */
class PlayModeFabric {
public:
    static Shuffle createShuffle(unsigned seed);
    static OddEven createOddEven();
    static Sequence createSequence();
};


#endif //JNP1_6_PROJECT_PLAYMODE_H
