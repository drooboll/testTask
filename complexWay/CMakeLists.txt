cmake_minimum_required(VERSION 3.5)
project(task-complex)

set(CMAKE_CXX_STANDARD 14)

set(SRC
    main.cpp
    ConsoleParser.cpp ConsoleParser.h
    Options.cpp Options.h
    Executor.cpp Executor.h
    Worker.cpp Worker.h
    Counter.cpp Counter.h
    Hasher.cpp Hasher.h
    Helper.cpp Helper.h
)

add_executable(${PROJECT_NAME} ${SRC})
