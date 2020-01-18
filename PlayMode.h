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

    PlayMode();
    explicit PlayMode(unsigned position);
    virtual ~PlayMode() = default;

    virtual std::shared_ptr<PlayMode> copyOf();
    virtual size_t next(size_t size);
    virtual void reset() {};
    void usageIncrement();
    int getUsage();

private:
    int usage;
protected:
    size_t position;
};


/**
 * @brief Suffle playmode derived class
 */
class Shuffle : public PlayMode {
public:
    size_t next(size_t size) override;
    void reset() override;
    std::shared_ptr<PlayMode> copyOf() override;

    explicit Shuffle(unsigned seed);
    ~Shuffle() override = default;

private:
    unsigned seed;
    std::vector<size_t> numbers;
    std::default_random_engine generator;
};

/**
 * @brief OddEven playmode derived class
 */
class OddEven : public PlayMode {
public:
    size_t next(size_t size) override;
    void reset() override;
    std::shared_ptr<PlayMode> copyOf() override;

    OddEven();
    ~OddEven() override = default;
};

/**
 * @brief Sequence playmode derived class
 */
class Sequence : public PlayMode {
public:
    size_t next(size_t size) override;
    void reset() override;
    std::shared_ptr<PlayMode> copyOf() override;

    Sequence();
    ~Sequence() override = default;
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
