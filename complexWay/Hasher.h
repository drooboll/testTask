#ifndef INC_2GISTASK_HASHER_H
#define INC_2GISTASK_HASHER_H

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
    int getResult() override;
    void printResult() override;
    void printErrorCause() override;
};


#endif //INC_2GISTASK_HASHER_H
