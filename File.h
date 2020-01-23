#ifndef JNP1_6_PROJECT_FILE_H
#define JNP1_6_PROJECT_FILE_H

#include <unordered_map>
#include "Playable.h"
#include "OpeningStrategy.h"

using StratCreateMethod = std::shared_ptr<OpeningStrategy>(*)();


class File {
public:
    std::shared_ptr<Playable> open(
            const std::unordered_map<std::string, StratCreateMethod>&) const;

    explicit File(const std::string &desc);

    ~File() = default;

private:
    std::string desc;
};

#endif //JNP1_6_PROJECT_FILE_H
