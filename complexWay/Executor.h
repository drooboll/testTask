#ifndef INC_2GISTASK_EXECUTOR_H
#define INC_2GISTASK_EXECUTOR_H

#include "ConsoleParser.h"
#include "Options.h"
#include "Worker.h"
#include <memory>

class Executor{
private:
    std::shared_ptr<Options> op;
    std::vector<std::shared_ptr<Worker>> workers;
public:
    explicit Executor(std::shared_ptr<ConsoleParser> cp);
    ~Executor();
    void startChain();
};


#endif //INC_2GISTASK_EXECUTOR_H
