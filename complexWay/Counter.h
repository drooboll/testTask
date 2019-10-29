#pragma once

#include <fstream>
#include "Worker.h"

class Counter: public Worker{
private:
    std::ifstream file;
    int count;
    std::string needle;
public:
    Counter(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op);
    bool work() override;
    void printResult() override;
};