
#ifndef INC_2GISTASK_WORKER_H
#define INC_2GISTASK_WORKER_H

#include <iostream>
#include <memory>
#include "ConsoleParser.h"
#include "Options.h"


class Worker{
protected:
    int error = 0;
    std::shared_ptr<ConsoleParser> cp;
    std::shared_ptr<Options> op;
public:
    Worker(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op);
    ~Worker();
    virtual bool work();
    // Bad idea
    virtual int getResult();
    virtual void printResult();
    virtual int getError();
    virtual void printErrorCause();
};

#endif //INC_2GISTASK_WORKER_H
