#include <regex>
#include "boost/algorithm/string.hpp"
#include "File.h"
#include "PlayerException.h"


using StratCreateMethod = std::shared_ptr<OpeningStrategy>(*)(); //jak bylo tylko w h to nie kompilowal sie

File::File(const std::string &desc) : desc(desc) {}

std::unordered_map<std::string, StratCreateMethod>& File::strats() {
  static std::unordered_map<std::string, StratCreateMethod> str;
  return str;
}

bool File::registerStrat(const std::string name, StratCreateMethod strat) {
    strats()[name] = strat;
    return true;
}

std::shared_ptr<Playable> File::open() const {
  auto stratCons = strats().find(desc.substr(0, desc.find('|')));
  if (stratCons != strats().end()) {
    return stratCons->second()->open(desc);
  }
  else {
    throw InvalidType();
    return nullptr;
  }
}

std::shared_ptr<OpeningStrategy> OpenSong::createStrat() {
  return std::dynamic_pointer_cast<OpeningStrategy>(std::make_shared<OpenSong>());
}

bool OpenSong::registered = File::registerStrat("audio", OpenSong::createStrat);


std::shared_ptr<Playable> OpenSong::open(const std::string &desc) {
  std::vector<std::string> result;
  boost::split(result, desc, boost::is_any_of("|"));
  std::string artist, title, other = "";
  bool artPresent = false, titlePresent = false;
  for (size_t i = 1; i < result.size() - 1; ++i) {
    size_t delimPos = result[i].find(':');
    if (delimPos == std::string::npos) {
      throw InvalidMetadata();
    }
    std::string metadataName = result[i].substr(0, delimPos);
    
    if (metadataName == "artist") {
      artPresent = true;
      artist = result[i].substr(delimPos + 1, result[i].size() - delimPos - 1);
    }
    else if (metadataName == "title") {
      titlePresent = true;
      title = result[i].substr(delimPos + 1, result[i].size() - delimPos - 1);
    }
    else {
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
  return std::make_shared<Song>(artist, title, other, result[result.size() - 1]);
}

std::shared_ptr<OpeningStrategy> OpenMovie::createStrat() {
  return std::dynamic_pointer_cast<OpeningStrategy>(std::make_shared<OpenMovie>());
}

bool OpenMovie::registered = File::registerStrat("video", 
                                                 OpenMovie::createStrat);

void OpenMovie::rot13(std::string &str) {
  for (char &c : str) {
    if (c > 'a' && c < 'z') {
      c = (c - 97 + 13) % 26 + 97;
    }
    if (c > 'A' && c < 'Z') {
      c = (c - 65 + 13) % 26 + 65;
    }
  }
}

std::shared_ptr<Playable> OpenMovie::open(const std::string &desc) {
  std::vector<std::string> result;
  boost::split(result, desc, boost::is_any_of("|"));
  std::string yearStr, title, other = "";
  size_t year;
  bool yearPresent = false, titlePresent = false;
  for (size_t i = 1; i < result.size() - 1; ++i) {
    size_t delimPos = result[i].find(':');
    if (delimPos == std::string::npos) {
      throw InvalidMetadata();
    }
    std::string metadataName = result[i].substr(0, delimPos);
    
    if (metadataName == "year") {
      yearStr = result[i].substr(delimPos + 1, result[i].size() - delimPos - 1);
      std::regex reg("^[0-9][1-9]*$");
      if (!std::regex_match(yearStr, reg)) {
        continue;
      }
      try {
        year = std::stoi(yearStr);
      }
      catch (const std::out_of_range &exception) {
        continue;
      }
      yearPresent = true;
    }
    else if (metadataName == "title") {
      titlePresent = true;
      title = result[i].substr(delimPos + 1, result[i].size() - delimPos - 1);
    }
    else {
      other += result[i];
    }
  }
  if (!(yearPresent && titlePresent)) {
    throw InvalidMetadata();
  }
  std::regex reg("^[A-Za-z0-9,.!?':;\\-\\s]*$");
  if (!std::regex_match(result[result.size() - 1], reg)) {
    throw InvalidFileContent();
  }
  rot13(result[result.size() - 1]);
  return std::make_shared<Movie>(year, title, other, result[result.size() - 1]);
}