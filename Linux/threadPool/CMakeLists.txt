cmake_minimum_required(VERSION 3.5)
project(threadPool)

find_package(Threads REQUIRED)

add_executable(threadPool main.cpp)
target_link_libraries(threadPool PRIVATE Threads::Threads)
