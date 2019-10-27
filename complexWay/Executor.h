#ifndef INC_2GISTASK_EXECUTOR_H
#define INC_2GISTASK_EXECUTOR_H

#include "ConsoleParser.h"
#include "Options.h"
#include "Worker.h"

class Executor{
private:
    Options op;
    std::vector<Worker*> workers;
public:
    explicit Executor(ConsoleParser& cp);
    void startChain();
};


#endif //INC_2GISTASK_EXECUTOR_H
