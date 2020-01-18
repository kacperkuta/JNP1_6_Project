//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYEREXCEPTION_H
#define JNP1_6_PROJECT_PLAYEREXCEPTION_H

class PlayerException : public std::exception {
public:
    virtual const char* what() {
        return "PlayerException";
    }
};

class IncorrectPosition : public PlayerException {
public:
    const char* what() override {
        return "Incorrect Playlist add/remove position";
    }
};

class EmptyPlaylistRemove : public PlayerException {
public:
    const char* what() override {
        return "Remove called on empty Playlist";
    }
};

#endif //JNP1_6_PROJECT_PLAYEREXCEPTION_H
