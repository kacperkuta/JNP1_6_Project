#include <iostream>
#include <algorithm>
#include <cassert>
#include "PlayMode.h"

PlayMode::PlayMode() : usage(0), position(0) {};

PlayMode::PlayMode(unsigned position) : usage(0), position(position) {};

int PlayMode::getUsage() {
    return usage;
}

void PlayMode::usageIncrement() {
    usage++;
}

Shuffle::Shuffle(unsigned seed)
        : PlayMode(), generator(std::default_random_engine(seed)), seed(seed),
          numbers(std::vector<size_t>()) {}

size_t Shuffle::next(size_t size) {
    if (numbers.empty()) {
        for (size_t i = 0; i < size; i++)
            numbers.push_back(i);
        std::shuffle(numbers.begin(), numbers.end(), generator);
    }
    position++;
    return numbers[position - 1];
}

void Shuffle::reset() {
    numbers.clear();
    position = 0;
    assert(numbers.empty());
}

std::shared_ptr<PlayMode> Shuffle::copyOf() {
    return PlayModeFabric::createShuffle(seed);
}

OddEven::OddEven() : PlayMode(1) {};

size_t OddEven::next(size_t size) {
    if (position >= size && position % 2 == 1) {
        position = 2;
        return 0;
    } else {
        size_t toReturn = position;
        position += 2;
        return toReturn;
    }
}

void OddEven::reset() {
    position = 1;
}

Sequence::Sequence() : PlayMode() {};

std::shared_ptr<PlayMode> OddEven::copyOf() {
    return PlayModeFabric::createOddEven();
}

size_t Sequence::next(size_t size) {
    size_t toReturn = position;
    if (position < size - 1)
        position++;
    return toReturn;
}

void Sequence::reset() {
    position = 0;
}

std::shared_ptr<PlayMode> Sequence::copyOf() {
    return PlayModeFabric::createSequence();
}

std::shared_ptr<Shuffle> PlayModeFabric::createShuffle(unsigned seed) {
    return std::make_shared<Shuffle>(seed);
}

std::shared_ptr<OddEven> PlayModeFabric::createOddEven() {
    return std::make_shared<OddEven>();
}

std::shared_ptr<Sequence> PlayModeFabric::createSequence() {
    return std::make_shared<Sequence>();
}


