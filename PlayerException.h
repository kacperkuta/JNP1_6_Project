//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYEREXCEPTION_H
#define JNP1_6_PROJECT_PLAYEREXCEPTION_H

class PlayerException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "PlayerException";
    }
};

class IncorrectPosition : public PlayerException {
public:
    const char* what() const throw() override {
        return "Incorrect Playlist add/remove position";
    }
};

class EmptyPlaylistRemove : public PlayerException {
public:
    const char* what() const throw() override {
        return "Remove called on empty Playlist";
    }
};

class InvalidType : public PlayerException {
public:
    const char* what() const throw() override {
        return "Invalid type of file";
    }
};

class InvalidMetadata : public PlayerException {
public:
    const char* what() const throw() override {
        return "Invalid metadata";
    }
};

class InvalidFileContent : public PlayerException {
public:
    const char* what() const throw() override {
        return "Invalid file content";
    }
};
#endif //JNP1_6_PROJECT_PLAYEREXCEPTION_H
