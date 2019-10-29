#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdbool>

class ConsoleParser{
private:
    std::vector<std::string> opts;

    auto _getIterator(const std::string& option) const;
public:
    ConsoleParser(int argc, char** argv);
    ~ConsoleParser() = default;

    bool optExists(const std::string& option) const;

    std::string getOptValue(const std::string& option) const;

    std::string getProgramName();
};
