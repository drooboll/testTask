#include "ConsoleParser.h"

ConsoleParser::ConsoleParser(int argc, char **argv) {
    // First string is filename (most of cases), but should it be skipped?
    for (int i = 0; i < argc; ++i){
        opts.push_back(std::string(argv[i]));
    }
}

bool ConsoleParser::optExists(const std::string &option) const{
    auto iterator = std::find(opts.begin(), opts.end(), option);
    return iterator != opts.end();
}

std::string ConsoleParser::getOptValue(const std::string &option) const{
    auto iterator = std::find(opts.begin(), opts.end(), option);
    if (iterator != opts.end() && ++iterator != opts.end()){
        if ((*iterator)[0] != '-')
        return *iterator;
    }
    // Empty by default
    static const std::string emptyStr;
    return emptyStr;
}
