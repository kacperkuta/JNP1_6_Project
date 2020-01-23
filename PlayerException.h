//
// Created by baka475 on 16.01.20.
//

#ifndef JNP1_6_PROJECT_PLAYEREXCEPTION_H
#define JNP1_6_PROJECT_PLAYEREXCEPTION_H

class PlayerException : public std::exception {
public:
    const char* what() const noexcept override {
        return "PlayerException";
    }
    ~PlayerException() override = default;
};

class IncorrectPosition : public PlayerException {
public:
    const char* what() const noexcept override {
        return "Incorrect Playlist add/remove position";
    }
};

class EmptyPlaylistRemove : public PlayerException {
public:
    const char* what() const noexcept override {
        return "Remove called on empty Playlist";
    }
};

class InvalidType : public PlayerException {
public:
    const char* what() const noexcept override {
        return "Invalid type of file";
    }
};

class InvalidMetadata : public PlayerException {
public:
    const char* what() const noexcept override {
        return "Invalid metadata";
    }
};

class InvalidFileContent : public PlayerException {
public:
    const char* what() const noexcept override {
        return "Invalid file content";
    }
};

class CyclicPlaylistInsertion : public PlayerException {
public:
    const char* what() const noexcept override {
        return "Playlist adding will cause infinite cyclic playing";
    }
};

#endif //JNP1_6_PROJECT_PLAYEREXCEPTION_H
