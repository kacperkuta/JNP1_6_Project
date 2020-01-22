#ifndef JNP1_6_PROJECT_FILE_H
#define JNP1_6_PROJECT_FILE_H

#include <unordered_map>
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

class File {
public:
  using StratCreateMethod = std::shared_ptr<OpeningStrategy>(*)();
  std::string desc;
  static bool registerStrat(const std::string name, StratCreateMethod strat);
  std::shared_ptr<Playable> open() const;
  File (const std::string &desc);
  ~File() = default;

private:
  static std::unordered_map<std::string, StratCreateMethod> &strats();
};

#endif //JNP1_6_PROJECT_FILE_H
