#ifndef INC_2GISTASK_OPTIONS_H
#define INC_2GISTASK_OPTIONS_H

#include <string>
#include <map>

struct Options{
public:
    enum{
        FILE_FLAG,
        MODE_FLAG,
        WORD_FLAG,
        HELP_FLAG,
        HELP_LONG_FLAG,
        ALGO_FLAG
    };

    enum{
        WORD_MODE,
        HASH_MODE
    };

    enum{
        CRC32,
        SUM,
        XOR
    };
    std::map<int, std::string> flags;
    std::map<int, std::string> flagAdditions;
    std::map<int, std::string> modes;
    std::map<int, std::string> algorithms;
    Options();
    ~Options();
};


#endif //INC_2GISTASK_OPTIONS_H
