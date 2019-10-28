#include <fstream>
#include <iostream>

#include "Counter.h"

Counter::Counter(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op): count(0), Worker(cp, op){
    if (cp->optExists(op->flags[op->FILE_FLAG])) {
        std::string filename = cp->getOptValue(op->flags[op->FILE_FLAG]);
        file = std::ifstream(filename, std::ofstream::in);
        if (!file)
            error = 2;
    } else {
        error = 1;
    }
}

bool Counter::work() {
    if (Worker::error == 0){
        if (cp->optExists(op->flags[op->MODE_FLAG])){
            if(cp->getOptValue(op->flags[op->MODE_FLAG]) == op->modes[op->WORD_MODE]){
                needle = cp->getOptValue(op->flags[op->WORD_FLAG]);
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
    bool ret = true;
    if (!needle.empty()){
        std::string line;
        size_t index;
        while(file.good()) {
            index = 0;
            std::getline(file, line);
            while((index = line.find(needle, index)) != std::string::npos) {
                index += needle.length();
                count++;
            }
        }
    } else {
        ret = false;
    }
    file.close();
    return ret;
}

int Counter::getResult() {
    return count;
}

void Counter::printResult() {
    std::cout << count << std::endl;
}

void Counter::printErrorCause() {
    Worker::printErrorCause();
}
