#ifndef INC_2GISTASK_CONSOLEPARSER_H
#define INC_2GISTASK_CONSOLEPARSER_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdbool>

class ConsoleParser{
private:
    std::vector<std::string> opts;

    auto _getIterator(std::string& option);

public:
    ConsoleParser(int argc, char** argv);
    ~ConsoleParser();

    bool optExists(std::string& option);

    bool optExists(const char* option);

    std::string getOptValue(std::string& option);

    std::string getOptValue(const char* option);

    std::string getProgramName();
};


#endif //INC_2GISTASK_CONSOLEPARSER_H
