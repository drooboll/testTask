cmake_minimum_required(VERSION 3.5)
project(task-complex)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< Updated upstream
=======
add_compile_options("-ggdb3")
>>>>>>> Stashed changes
add_executable(task-complex main.cpp ConsoleParser.cpp ConsoleParser.h Options.cpp Options.h Worker.cpp Worker.h Executor.cpp Executor.h Counter.cpp Counter.h Hasher.cpp Hasher.h Helper.cpp Helper.h)
