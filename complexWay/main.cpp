#include <memory>

#include "ConsoleParser.h"
#include "Executor.h"

int main(int argc, char** argv) {
    auto cp = std::make_shared<ConsoleParser>(argc, argv);
    auto ex = std::make_shared<Executor>(cp);
    ex->startChain();
    return 0;
}