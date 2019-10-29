#pragma once

#include "Worker.h"
#include <fstream>
#include <stdint.h>

class Hasher: public Worker{
private:
    std::ifstream file;
    uint32_t hash = 0;
    bool _calcCRC();
    bool _calcXOR();
    bool _calcSUM();
public:
    Hasher(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op);
    bool work() override;
    void printResult() override;
};
