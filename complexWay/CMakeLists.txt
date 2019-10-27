cmake_minimum_required(VERSION 3.13)
project(2gisTask)

set(CMAKE_CXX_STANDARD 14)

add_executable(2gisTask main.cpp ConsoleParser.cpp ConsoleParser.h Options.cpp Options.h Worker.cpp Worker.h Executor.cpp Executor.h Counter.cpp Counter.h Hasher.cpp Hasher.h Helper.cpp Helper.h)