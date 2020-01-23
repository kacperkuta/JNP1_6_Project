#include <regex>
#include <iostream>
#include "boost/algorithm/string.hpp"
#include "File.h"
#include "PlayerException.h"

File::File(const std::string &desc) : desc(desc) {}

std::shared_ptr<Playable> File::open(const std::unordered_map<std::string,
        StratCreateMethod>& strats) const {
    auto stratCons = strats.find(desc.substr(0, desc.find('|')));
    if (stratCons != strats.end()) {
        return stratCons->second()->open(desc);
    } else {
        throw InvalidType();
    }
}

