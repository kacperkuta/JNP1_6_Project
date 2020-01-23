cmake_minimum_required(VERSION 3.10)
project(JNP1_6_Project)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2 -std=c++17")

add_executable(JNP1_6_Project main.cpp Player.h Playable.h PlayMode.h File.h lib_playlist.h PlayerException.h Playable.cpp PlayMode.cpp File.cpp Player.cpp)
add_executable(test test.cpp Player.h Playable.h PlayMode.h File.h lib_playlist.h PlayerException.h Playable.cpp PlayMode.cpp File.cpp Player.cpp)
add_executable(example  playlist_example.cpp Player.h Playable.h PlayMode.h File.h lib_playlist.h PlayerException.h Playable.cpp PlayMode.cpp File.cpp Player.cpp)