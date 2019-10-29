#ifndef INC_2GISTASK_COUNTER_H
#define INC_2GISTASK_COUNTER_H

#include "Worker.h"

class Counter: public Worker{
private:
    std::ifstream* file;
    int count;
    std::string needle;
public:
    Counter(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op);
    bool work() override;
    int getResult() override;
    void printResult() override;
    void printErrorCause() override;
};


#endif //INC_2GISTASK_COUNTER_H
