#include <iostream>
#include "Options.h"

Options::Options() {
    flags.insert(std::make_pair(flagType::FILE_FLAG, std::string("-f")));
    flags.insert(std::make_pair(flagType::MODE_FLAG, std::string("-m")));
    flags.insert(std::make_pair(flagType::WORD_FLAG, std::string("-v")));
    flags.insert(std::make_pair(flagType::HELP_FLAG, std::string("-h")));
    flags.insert(std::make_pair(flagType::HELP_LONG_FLAG, std::string("--help")));
    flags.insert(std::make_pair(flagType::ALGO_FLAG, std::string("-a")));

    flagAdditions.insert(std::make_pair(flagType::FILE_FLAG, std::string("<filename>")));
    flagAdditions.insert(std::make_pair(flagType::MODE_FLAG, std::string("<mode>")));
    flagAdditions.insert(std::make_pair(flagType::WORD_FLAG, std::string("<word>")));
    flagAdditions.insert(std::make_pair(flagType::HELP_FLAG, std::string("")));
    flagAdditions.insert(std::make_pair(flagType::HELP_LONG_FLAG, std::string("")));
    flagAdditions.insert(std::make_pair(flagType::ALGO_FLAG, std::string("<algorithm>")));

    modes.insert(std::make_pair(modeType::WORD_MODE, std::string("words")));
    modes.insert(std::make_pair(modeType::HASH_MODE, std::string("checksum")));

    algorithms.insert(std::make_pair(algoType::SUM, std::string("SUM")));
    algorithms.insert(std::make_pair(algoType::XOR, std::string("XOR")));
    algorithms.insert(std::make_pair(algoType::CRC32, std::string("CRC32")));
}