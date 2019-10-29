#pragma once

#include "Worker.h"

class Helper: public Worker{
private:
    bool w = false;
public:
    Helper(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op): Worker(cp, op){}
    bool work() override;
    void printResult() override;
};
