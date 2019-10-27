#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "ConsoleParser.h"
#include "Executor.h"

int main(int argc, char** argv) {
    auto cp = new ConsoleParser(argc, argv);
    auto ex = new Executor(*cp);
    ex->startChain();

    return 0;
}