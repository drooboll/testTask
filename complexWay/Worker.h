
#ifndef INC_2GISTASK_WORKER_H
#define INC_2GISTASK_WORKER_H

#include <iostream>
#include "ConsoleParser.h"
#include "Options.h"


class Worker{
protected:
    int error = 0;
    ConsoleParser* cp;
    Options* op;
public:
    Worker(ConsoleParser& cp, Options& op);
    virtual bool work();
    // Bad idea
    virtual int getResult();
    virtual void printResult();
    virtual int getError();
    virtual void printErrorCause();
};

#endif //INC_2GISTASK_WORKER_H
