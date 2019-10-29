#pragma once

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
    ~Worker() = default;
    virtual bool work();
    virtual void printResult();
};