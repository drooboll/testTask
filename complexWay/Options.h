#pragma once

#include <string>
#include <map>

struct Options{
    enum class flagType{
        FILE_FLAG,
        MODE_FLAG,
        WORD_FLAG,
        HELP_FLAG,
        HELP_LONG_FLAG,
        ALGO_FLAG
    };

    enum class modeType{
        WORD_MODE,
        HASH_MODE
    };

    enum class algoType{
        CRC32,
        SUM,
        XOR
    };
    std::map<flagType, std::string> flags;
    std::map<flagType, std::string> flagAdditions;
    std::map<modeType, std::string> modes;
    std::map<algoType, std::string> algorithms;
    Options();
    ~Options() = default;
};