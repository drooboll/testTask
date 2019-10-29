#include "Worker.h"

Worker::Worker(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op) {
    this->cp = cp;
    this->op = op;
}

bool Worker::work() {
    std::cout << "Wrong or incomplete set of flags" << std::endl;
    std::cout << "Run " << cp->getProgramName() << " with " <<
              op->flags[Options::flagType::HELP_FLAG] << " or " << op->flags[Options::flagType::HELP_LONG_FLAG] <<
              " to see help." << std::endl;
    return true;
}

void Worker::printResult() {
    throw std::runtime_error("No arguments specified.");
}