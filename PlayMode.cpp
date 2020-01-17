#include "PlayMode.h"

Shuffle::Shuffle(unsigned seed) : generator(std::default_random_engine(seed)) {};

size_t Shuffle::next(size_t size) {
    return generator()%size;
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

Sequence::Sequence() : position(0) {};

size_t Sequence::next(size_t size) {
    size_t toReturn = position;
    if (position < size - 1)
        position++;
    return toReturn;
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

