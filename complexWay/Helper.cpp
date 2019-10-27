#include "Helper.h"

bool Helper::work() {
    if (cp->optExists(op->flags[op->HELP_FLAG]) || cp->optExists(op->flags[op->HELP_LONG_FLAG])){
        std::cout << "Usage: ";
        std::cout << cp->getProgramName() << " ";
        for (auto iterator : op->flags){
            if (!op->flagAdditions[iterator.first].empty())
                std::cout << "[" << iterator.second << " " << op->flagAdditions[iterator.first] << "] ";
            else
                std::cout << "[" << iterator.second << "] ";
        }
        std::cout << std::endl;
        std::cout << op->flagAdditions[op->FILE_FLAG] << ": file (path to file) to parse." << std::endl;
        std::cout << op->flagAdditions[op->MODE_FLAG] << ": " << op->modes[op->WORD_MODE] <<
        " to count occurencies of word, specified by " << op->flags[op->WORD_FLAG] << " flag, or " <<
        op->modes[op->HASH_MODE] << " to calculate checksum of data in file." << std::endl;
        std::cout << op->flagAdditions[op->WORD_FLAG] << ": specifies a word to find in file (without whitespaces)." << std::endl;
        std::cout << op->flagAdditions[op->ALGO_FLAG] << ": specifies checksum algorithm. Could be a 'SUM', 'XOR' or 'CRC32'. " <<
        "If none selected, algorithm is 'SUM'" << std::endl;
        return true;
    }
    // Actually it should not return any error
    error = 0;
    return false;
}

