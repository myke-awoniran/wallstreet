cmake_minimum_required(VERSION 4.1)
project(wallstreet)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(wallstreet
        src/CSVReader.cpp
        src/CSVReader.h
        src/main.cpp
        src/OrderBookEntry.cpp
        src/OrderBookEntry.h
        src/Services.cpp
        src/Services.h)