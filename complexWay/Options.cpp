//
// Created by valery on 26.10.19.
//

#include "Options.h"

Options::Options() {
    flags.insert(std::make_pair(FILE_FLAG, std::string("-f")));
    flags.insert(std::make_pair(MODE_FLAG, std::string("-m")));
    flags.insert(std::make_pair(WORD_FLAG, std::string("-v")));
    flags.insert(std::make_pair(HELP_FLAG, std::string("-h")));
    flags.insert(std::make_pair(HELP_LONG_FLAG, std::string("--help")));
    flags.insert(std::make_pair(ALGO_FLAG, std::string("-a")));

    flagAdditions.insert(std::make_pair(FILE_FLAG, std::string("<filename>")));
    flagAdditions.insert(std::make_pair(MODE_FLAG, std::string("<mode>")));
    flagAdditions.insert(std::make_pair(WORD_FLAG, std::string("<word>")));
    flagAdditions.insert(std::make_pair(HELP_FLAG, std::string("")));
    flagAdditions.insert(std::make_pair(HELP_LONG_FLAG, std::string("")));
    flagAdditions.insert(std::make_pair(ALGO_FLAG, std::string("<algorithm>")));

    modes.insert(std::make_pair(WORD_MODE, std::string("words")));
    modes.insert(std::make_pair(HASH_MODE, std::string("checksum")));

    algorithms.insert(std::make_pair(SUM, std::string("SUM")));
    algorithms.insert(std::make_pair(XOR, std::string("XOR")));
    algorithms.insert(std::make_pair(CRC32, std::string("CRC32")));
}