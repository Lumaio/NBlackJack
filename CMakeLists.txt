cmake_minimum_required(VERSION 2.8.4)
project(NBlackJack)

set(SOURCE_FILES main.cpp Deck.cpp)
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
add_executable(NBlackJack ${SOURCE_FILES})
target_link_libraries(NBlackJack ncurses)