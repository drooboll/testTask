#include "Helper.h"

bool Helper::work() {
    return cp->optExists(op->flags[Options::flagType::HELP_FLAG]) ||
    cp->optExists(op->flags[Options::flagType::HELP_LONG_FLAG]);
}

void Helper::printResult() {
    std::cout << "Usage: ";
    std::cout << cp->getProgramName() << " ";
    for (auto& iterator : op->flags){
        if (!op->flagAdditions[iterator.first].empty())
            std::cout << "[" << iterator.second << " " << op->flagAdditions[iterator.first] << "] ";
        else
            std::cout << "[" << iterator.second << "] ";
    }
    std::cout << std::endl;
    std::cout << op->flagAdditions[Options::flagType::FILE_FLAG] << ": file (path to file) to parse." << std::endl;
    std::cout << op->flagAdditions[Options::flagType::MODE_FLAG] << ": " << op->modes[Options::modeType::WORD_MODE] <<
              " to count occurencies of word, specified by " << op->flags[Options::flagType::WORD_FLAG] << " flag, or " <<
              op->modes[Options::modeType::HASH_MODE] << " to calculate checksum of data in file." << std::endl;
    std::cout << op->flagAdditions[Options::flagType::WORD_FLAG] << ": specifies a word to find in file (without whitespaces)." << std::endl;
    std::cout << op->flagAdditions[Options::flagType::ALGO_FLAG] << ": specifies checksum algorithm. Could be a 'SUM', 'XOR' or 'CRC32'. " <<
              "If none selected, algorithm is 'SUM'" << std::endl;
}

