#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

#include "ConsoleParser.h"
#include "Executor.h"

int main(int argc, char** argv) {
    std::shared_ptr<ConsoleParser> cp(new ConsoleParser(argc, argv));
    std::unique_ptr<Executor> ex(new Executor(cp));
    ex->startChain();
    return 0;
}