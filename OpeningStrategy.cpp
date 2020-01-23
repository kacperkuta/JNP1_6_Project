#include "OpeningStrategy.h"
#include "PlayerException.h"
#include <regex>
#include <iostream>
#include "boost/algorithm/string.hpp"

std::shared_ptr<OpeningStrategy> OpenSong::createStrat() {
    return std::make_shared<OpenSong>();
}

std::shared_ptr<Playable> OpenSong::open(const std::string &desc) {
    std::vector<std::string> result;
    boost::split(result, desc, boost::is_any_of("|"));
    std::string artist, title, other;
    bool artPresent = false, titlePresent = false;
    for (size_t i = 1; i < result.size() - 1; ++i) {
        size_t delimPos = result[i].find(':');
        if (delimPos == std::string::npos) {
            throw InvalidMetadata();
        }
        std::string metadataName = result[i].substr(0, delimPos);

        if (metadataName == "artist") {
            artPresent = true;
            artist = result[i].substr(delimPos + 1,
                                      result[i].size() - delimPos - 1);
        } else if (metadataName == "title") {
            titlePresent = true;
            title = result[i].substr(delimPos + 1,
                                     result[i].size() - delimPos - 1);
        } else {
            other += result[i];
        }
    }
    if (!(artPresent && titlePresent)) {
        throw InvalidMetadata();
    }
    std::regex reg("^[A-Za-z0-9,.!?':\\-;\\s]*$");
    if (!std::regex_match(result[result.size() - 1], reg)) {
        throw InvalidFileContent();
    }
    return std::make_shared<Song>(artist, title, other,
                                  result[result.size() - 1]);
}

std::shared_ptr<OpeningStrategy> OpenMovie::createStrat() {
    return std::make_shared<OpenMovie>();
}

std::shared_ptr<Playable> OpenMovie::open(const std::string &desc) {
    std::vector<std::string> result;
    boost::split(result, desc, boost::is_any_of("|"));
    std::string yearStr, title, other;
    size_t year;
    bool yearPresent = false, titlePresent = false;
    for (size_t i = 1; i < result.size() - 1; ++i) {
        size_t delimPos = result[i].find(':');
        if (delimPos == std::string::npos) {
            throw InvalidMetadata();
        }
        std::string metadataName = result[i].substr(0, delimPos);

        if (metadataName == "year") {
            yearStr = result[i].substr(delimPos + 1,
                                       result[i].size() - delimPos - 1);
            std::regex reg("^[1-9][0-9]*$");
            if (!std::regex_match(yearStr, reg) && yearStr != "0") {
                yearPresent = false;
                continue;
            }
            try {
                year = (size_t) std::stoi(yearStr);
            }
            catch (const std::out_of_range &exception) {
                yearPresent = false;
                continue;
            }
            yearPresent = true;
        } else if (metadataName == "title") {
            titlePresent = true;
            title = result[i].substr(delimPos + 1,
                                     result[i].size() - delimPos - 1);
        } else {
            other += result[i];
        }
    }
    if (!(yearPresent && titlePresent)) {
        std::cout << yearPresent << " " << titlePresent << "\n";
        throw InvalidMetadata();
    }
    std::regex reg("^[A-Za-z0-9,.!?':;\\-\\s]*$");
    if (!std::regex_match(result[result.size() - 1], reg)) {
        throw InvalidFileContent();
    }
    rot13(result[result.size() - 1]);
    return std::make_shared<Movie>(year, title, other,
                                   result[result.size() - 1]);
}

void OpenMovie::rot13(std::string &str) {
    for (char &c : str) {
        if (c > 'a' && c < 'z') {
            c = (char) ((c - (char) 'a' + 13) % 26 + (char) 'a');
        }
        if (c > 'A' && c < 'Z') {
            c = (char) ((c - (char) 'A' + 13) % 26 + (char) 'A');
        }
    }
}
