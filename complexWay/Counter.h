#ifndef INC_2GISTASK_COUNTER_H
#define INC_2GISTASK_COUNTER_H

#include "Worker.h"

class Counter: Worker{
private:
    std::ifstream* file;
    int count;
    std::string needle;
public:
    Counter(ConsoleParser& cp, Options& op);
    bool work() override;
    int getResult() override;
    void printResult() override;
};


#endif //INC_2GISTASK_COUNTER_H
