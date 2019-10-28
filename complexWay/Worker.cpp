#include <iostream>
#include <fstream>
#include "Worker.h"

Worker::Worker(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op) {
    this->cp = cp;
    this->op = op;
}

Worker::~Worker(){
}

bool Worker::work() {
    std::cout << "Wrong or incomplete set of flags" << std::endl;
    std::cout << "Run " << cp->getProgramName() << " with " <<
              op->flags[op->HELP_FLAG] << " or " << op->flags[op->HELP_LONG_FLAG] <<
              " to see help." << std::endl;
    return true;
}

int Worker::getResult() {
    return 0;
}

void Worker::printResult() {

}

void Worker::printErrorCause() {
    // Actually strings should be stored somewhere like `Options` class
    switch(error){
        case 0:
            // That should never happen (:
            std::cerr << "No error" << std::endl;
            break;
        case 1:
            std::cerr << "No file flag." << std::endl;
            break;
        case 2:
            std::cerr << "File not found: " << cp->getOptValue(op->flags[op->FILE_FLAG]) << std::endl;
            break;
        default:
            std::cerr << "Generic error." << std::endl;
    }
}

int Worker::getError() {
    return error;
}