cmake_minimum_required(VERSION 3.10)
project(JNP1_6_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(JNP1_6_Project main.cpp Player.h Playable.h PlayMode.h File.h lib_playlist.h PlayerException.h Playable.cpp PlayMode.cpp File.cpp Player.cpp)
#add_executable(test test.cpp)