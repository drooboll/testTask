#include "Hasher.h"

Hasher::Hasher(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op): Worker(cp, op){
    if (cp->optExists(op->flags[op->FILE_FLAG])) {
        std::string filename = cp->getOptValue(op->flags[op->FILE_FLAG]);
        file = new std::ifstream(filename, std::ofstream::in);
        if (!file)
            error = 2;
    } else {
        error = 1;
    }
}
bool Hasher::_calcSUM() {
    uint32_t word;
    while(*file >> word){
        // What should be done if hash overflows?
        hash += word;
    }
    if (!file->eof()){
        Worker::error = 3;
        return false;
    }
    return true;
}

bool Hasher::_calcXOR() {
    uint32_t word;
    while(*file >> word){
        hash ^= word;
    }
    if (!file->eof()){
        Worker::error = 3;
        return false;
    }
    return true;
}

bool Hasher::_calcCRC() {
    uint32_t crc_table[256];

    uint32_t polynomial = 0xEDB88320;
    for (uint32_t i = 0; i < 256; i++){
        uint32_t c = i;
        for (uint32_t j = 0; j < 8; j++) {
            if (c & 1) {
                c = polynomial ^ (c >> 1);
            }
            else {
                c >>= 1;
            }
        }
        crc_table[i] = c;
    };

    uint32_t crc = 0xFFFFFFFF;

    char symbol;
    while(file->get(symbol)){
        crc = crc_table[(crc ^ symbol) & 0xFF] ^ (crc >> 8);
    }
    if (!file->eof()){
        Worker::error = 3;
        return false;
    }
    hash =  crc ^ 0xFFFFFFFF;
    return true;
}

bool Hasher::work() {
    if (Worker::error != 0)
        return false;
    if (cp->optExists(op->flags[op->MODE_FLAG])){
        if(cp->getOptValue(op->flags[op->MODE_FLAG]) == op->modes[op->HASH_MODE]){
            if (cp->optExists(op->flags[op->ALGO_FLAG])){
                std::string algorithm = cp->getOptValue(op->flags[op->ALGO_FLAG]);
                if (!algorithm.empty()){
                    bool retVal = false;
                    for (auto algo: op->algorithms){
                        if (algo.second == algorithm){
                            if (algo.first == op->SUM){
                                retVal = _calcSUM();
                                break;
                            }
                            if (algo.first == op->XOR){
                                retVal = _calcXOR();
                                break;
                            }
                            if (algo.first == op->CRC32){
                                retVal = _calcCRC();
                                break;
                            }

                        }
                    }
                    if (!retVal){
                        error = 3;
                        return false;
                    } else
                        return true;
                }
            }
            bool retVal = _calcSUM();
            file->close();
            return retVal;
        }
    }
    return false;
}

int Hasher::getResult() {
    return hash;
}

void Hasher::printResult(){
    if (!Worker::error)
        std::cout << hash << std::endl;
}

void Hasher::printErrorCause() {
    if (Worker::error != 3){
        Worker::printErrorCause();
    } else {
        std::cerr << "File consists not only of integers, aborting." << std::endl;
    }
}