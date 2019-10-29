#include <iostream>
#include <fstream>
#include <memory>

#include "ConsoleParser.h"
#include "Executor.h"

int main(int argc, char** argv) {
    std::shared_ptr<ConsoleParser> cp(new ConsoleParser(argc, argv));
    Executor ex(cp);
    try{
        ex.doWork();
    } catch (std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}