#include "Executor.h"
#include "ConsoleParser.h"


Executor::Executor( std::shared_ptr<ConsoleParser>& cp) {
    this->cp = cp;
}

void Executor::doWork() {
    if (cp->optExists("-h")){
        printHelp();
        return;
    }

    if (!cp->optExists("-f")){
        throw std::runtime_error("No file specified");
    }

    if (!cp->optExists("-m")){
        throw std::runtime_error("No mode specified");
    }

    std::string filename = cp->getOptValue("-f");
    std::ifstream file(filename, std::fstream::in);
    std::string mode = cp->getOptValue("-m");

    if (!file)
        throw std::runtime_error(std::string("Bad file: \"").append(filename).append("\""));
    if (mode == "words"){
        if (!cp->optExists("-v"))
            throw std::runtime_error("No word specified");
        std::string word = cp->getOptValue("-v");
        if(word.empty())
            throw std::runtime_error("No word specified");

        int count = 0;
        std::string line;
        size_t index;
        while(file.good()) {
            index = 0;
            std::getline(file, line);
            while((index = line.find(word, index)) != std::string::npos) {
                index += word.length();
                count++;
            }
        }
        std::cout << count << std::endl;

    } else {
        if (mode == "checksum"){
            uint32_t hash = 0;
            uint32_t word;
            while(file >> word){
                // What should be done if hash overflows?
                hash += word;
            }
            if (!file.eof()){
                throw std::runtime_error("Checksum error: not only integers in file");
            }
            std::cout << hash << std::endl;
            file.close();
        }
    }
    file.close();
}

void Executor::printHelp(){
    std::cout << "Usage: [-f <file>] [-m <mode>] [-v <word>] [-h]" << std::endl;
    std::cout << "<file>: file (path to file) to parse." << std::endl;
    std::cout << "<mode>: 'words' to count occurencies of word, specified by -v flag, or 'checksum' to calculate checksum of data in file." << std::endl;
    std::cout << "<word>: specifies a word to find in file (without whitespaces)." << std::endl;
}