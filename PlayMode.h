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
};


/**
 * @brief Suffle playmode derived class
 */
class Shuffle : PlayMode {
public:
    size_t next(size_t size) override;
    explicit Shuffle(unsigned seed);

private:
    std::default_random_engine generator;
};

/**
 * @brief OddEven playmode derived class
 */
class OddEven : PlayMode {
public:
    size_t next(size_t size) override;
    OddEven();
private:
    size_t position;
};

/**
 * @brief Sequence playmode derived class
 */
class Sequence : PlayMode {
public:
    size_t next(size_t size) override;
    Sequence();
private:
    size_t position;
};

/**
 * @brief Fabric of playmodes.
 */
class PlayModeFabric {
public:
    static std::shared_ptr<Shuffle> createShuffle(unsigned seed);
    static std::shared_ptr<OddEven> createOddEven();
    static std::shared_ptr<Sequence> createSequence();
};


#endif //JNP1_6_PROJECT_PLAYMODE_H
