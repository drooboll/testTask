#include <iostream>
#include <fstream>

#include "ConsoleParser.h"

void printHelp(){
    std::cout << "Usage: [-f <file>] [-m <mode>] [-v <word>] [-h]" << std::endl;
    std::cout << "<file>: file (path to file) to parse." << std::endl;
    std::cout << "<mode>: 'words' to count occurencies of word, specified by -v flag, or 'checksum' to calculate checksum of data in file." << std::endl;
    std::cout << "<word>: specifies a word to find in file (without whitespaces)." << std::endl;
}

void printIncomplete(){
    std::cerr << "Wrong or incomplete flags. See help (-h flag)." << std::endl;
}

void printFileNotFound(std::string& name){
    std::cerr << "File " << name << " not found." << std::endl;
}

void printSumError(){
    std::cerr << "Checksum error." << std::endl;
}


int main(int argc, char** argv) {
    auto cp = new ConsoleParser(argc, argv);
    if (cp->optExists("-h")){
        printHelp();
    } else {
        if (cp->optExists("-f")){
            std::string filename = cp->getOptValue("-f");
            if (!filename.empty()){
                if (cp->optExists("-m")){
                    std::string mode = cp->getOptValue("-m");
                    if (mode == "words"){
                        if (cp->optExists("-v")){
                            std::string word = cp->getOptValue("-v");
                            if (!word.empty()){
                                std::ifstream file(filename, std::fstream::in);
                                if (file){
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
                                    printFileNotFound(filename);
                                }
                            } else {
                                printIncomplete();
                            }
                        }
                    } else {
                        if (mode == "checksum"){
                            std::ifstream file(filename, std::fstream::in);
                            if (file){
                                uint32_t hash = 0;
                                uint32_t word;
                                while(file >> word){
                                    // What should be done if hash overflows?
                                    hash += word;
                                }
                                if (!file.eof()){
                                    printSumError();
                                    return -1;
                                }
                                std::cout << hash << std::endl;
                            } else {
                                printFileNotFound(filename);
                            }
                        } else {
                            printIncomplete();
                        }
                    }
                }
            } else {
                printIncomplete();
            }
        } else {
            printIncomplete();
        }
    }
    return 0;
}