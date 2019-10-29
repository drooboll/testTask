#include <iostream>
#include "ConsoleParser.h"

auto ConsoleParser::_getIterator(std::string &option) {
    return std::find(opts.begin(), opts.end(), option);
}

ConsoleParser::ConsoleParser(int argc, char **argv) {
    // First string is filename (most of cases), but should it be skipped?
    for (int i = 0; i < argc; ++i){
        opts.emplace_back(std::string(argv[i]));
    }
}

bool ConsoleParser::optExists(std::string &option) {
    auto iterator = _getIterator(option);
    return iterator != opts.end();
}

bool ConsoleParser::optExists(const char *option) {
    std::string stringOpt = std::string(option);
    return optExists(stringOpt);
}

std::string ConsoleParser::getOptValue(std::string &option) {
    auto iterator = _getIterator(option);
    if (iterator != opts.end() && ++iterator != opts.end()){
        if ((*iterator)[0] != '-')
        return *iterator;
    }
    // Empty by default
    static const std::string emptyStr;
    return emptyStr;
}

std::string ConsoleParser::getOptValue(const char* option) {
    std::string stringOpt = std::string(option);
    return getOptValue(stringOpt);
}

std::string ConsoleParser::getProgramName() {
    return opts[0];
}

ConsoleParser::~ConsoleParser() {
    this->opts.clear();
}


