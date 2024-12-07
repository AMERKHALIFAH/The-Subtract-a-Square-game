cmake_minimum_required(VERSION 3.28)
project(Assignment_Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_Demo
        BoardGame_Classes.h
        main.cpp
        MinMaxPlayer.h
        FourInARowGame.h
        FourInARowGame.cpp)
