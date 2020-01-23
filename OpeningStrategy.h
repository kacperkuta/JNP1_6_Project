#ifndef JNP1_6_PROJECT_OPENINGSTRATEGY_H
#define JNP1_6_PROJECT_OPENINGSTRATEGY_H

#include "Playable.h"

class OpeningStrategy {
public:
    virtual std::shared_ptr<Playable> open(const std::string &desc) = 0;
};

class OpenSong : public OpeningStrategy {
public:
    std::shared_ptr<Playable> open(const std::string &desc) override;

    static std::shared_ptr<OpeningStrategy> createStrat();

private:
    static bool registered;
};

class OpenMovie : public OpeningStrategy {
public:
    std::shared_ptr<Playable> open(const std::string &desc) override;

    static std::shared_ptr<OpeningStrategy> createStrat();

private:
    static void rot13(std::string &str);

    static bool registered;
};


#endif //JNP1_6_PROJECT_OPENINGSTRATEGY_H
