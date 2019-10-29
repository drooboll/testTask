#include "Counter.h"

Counter::Counter(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op): count(0), Worker(cp, op){
    if (cp->optExists(op->flags[Options::flagType::FILE_FLAG])) {
        std::string filename = cp->getOptValue(op->flags[Options::flagType::FILE_FLAG]);
        file = std::ifstream(filename, std::ofstream::in);
    }
}

bool Counter::work() {
    if (!file)
        throw std::runtime_error("File not specified");
    if (!cp->optExists(op->flags[Options::flagType::MODE_FLAG])){
        return false;
    }
    if(cp->getOptValue(op->flags[Options::flagType::MODE_FLAG]) == op->modes[Options::modeType::WORD_MODE]){
        needle = cp->getOptValue(op->flags[Options::flagType::WORD_FLAG]);
    } else {
        return false;
    }
    if (needle.empty()){
        throw std::runtime_error("Empty word");
    }
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
    file.close();
    return true;
}

void Counter::printResult() {
    std::cout << count << std::endl;
}