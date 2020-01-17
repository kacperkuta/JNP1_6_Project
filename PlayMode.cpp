#include <iostream>
#include "PlayMode.h"

Shuffle::Shuffle(unsigned seed)
    : generator(std::default_random_engine(seed))
    , seed(seed) {}

size_t Shuffle::next(size_t size) {
    return generator()%size;
}

void Shuffle::reset() {
    generator = std::default_random_engine(seed);
}

OddEven::OddEven() : position(1) {};

size_t OddEven::next(size_t size) {
    if (position == size - 1 || position == size - 2) {
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

Sequence::Sequence() : position(0) {};

size_t Sequence::next(size_t size) {
    size_t toReturn = position;
    if (position < size - 1) {
        position++;
    }
    return toReturn;
}

void Sequence::reset() {
    position = 0;
}

Shuffle PlayModeFabric::createShuffle(unsigned seed) {
    return Shuffle(seed);
}

OddEven PlayModeFabric::createOddEven() {
    return OddEven();
}

Sequence PlayModeFabric::createSequence() {
    return Sequence();
}

/**
 * @brief Dummy for proper compiling.
 * @param size unused
 * @return 0
 */
size_t PlayMode::next(size_t size) {
    return 0;
}

