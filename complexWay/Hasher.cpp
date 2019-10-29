#include "Hasher.h"

Hasher::Hasher(std::shared_ptr<ConsoleParser> cp, std::shared_ptr<Options> op): Worker(cp, op){
    if (cp->optExists(op->flags[Options::flagType::FILE_FLAG])) {
        std::string filename = cp->getOptValue(op->flags[Options::flagType::FILE_FLAG]);
        file = std::ifstream(filename, std::ofstream::in);
    }
}
bool Hasher::_calcSUM() {
    uint32_t word;
    while(file >> word){
        // What should be done if hash overflows?
        hash += word;
    }
    if (!file.eof()){
        throw std::runtime_error("There are not only integers in file");
    }
    file.close();
    return true;
}

bool Hasher::_calcXOR() {
    uint32_t word;
    while(file >> word){
        hash ^= word;
    }
    if (!file.eof()){
        throw std::runtime_error("There are not only integers in file");
    }
    file.close();
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
    while(file.get(symbol)){
        crc = crc_table[(crc ^ symbol) & 0xFF] ^ (crc >> 8);
    }
    if (!file.eof()){
        throw std::runtime_error("There are not only integers in file");
    }
    file.close();
    hash =  crc ^ 0xFFFFFFFF;
    return true;
}

bool Hasher::work() {
    if (!file)
        throw std::runtime_error("File not specified");
    if (!cp->optExists(op->flags[Options::flagType::MODE_FLAG])){
        return false;
    }
    if(cp->getOptValue(op->flags[Options::flagType::MODE_FLAG]) != op->modes[Options::modeType::HASH_MODE]){
        return false;
    }
    if (cp->optExists(op->flags[Options::flagType::ALGO_FLAG])){
        std::string algorithm = cp->getOptValue(op->flags[Options::flagType::ALGO_FLAG]);
        if (!algorithm.empty()){
            for (auto& algo: op->algorithms){
                if (algo.second == algorithm){
                    if (algo.first == Options::algoType::SUM){
                        return _calcSUM();
                    }
                    if (algo.first == Options::algoType::XOR){
                        return _calcXOR();
                    }
                    if (algo.first == Options::algoType::CRC32){
                        return _calcCRC();
                    }
                }
            }
        }
    }
    return _calcSUM();
}

void Hasher::printResult(){
    if (!Worker::error)
        std::cout << hash << std::endl;
}