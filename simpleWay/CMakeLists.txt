cmake_minimum_required(VERSION 3.5)
project(task-simple)

set(CMAKE_CXX_STANDARD 14)

add_executable(task-simple main.cpp ConsoleParser.cpp Executor.h Executor.cpp ConsoleParser.h)
