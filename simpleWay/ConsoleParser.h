#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <cstdbool>

class ConsoleParser{
private:
    std::vector<std::string> opts;

public:
    ConsoleParser(int argc, char** argv);

    ~ConsoleParser() = default;

    bool optExists(const std::string& option) const;

    std::string getOptValue(const std::string& option) const;

};