#pragma once

#include <memory>
#include <iostream>
#include <fstream>
#include "ConsoleParser.h"


class Executor {
private:
    std::shared_ptr<ConsoleParser> cp;
    void printHelp();
public:
    Executor(std::shared_ptr<ConsoleParser>& cp);

    void doWork();
};