//
// Created by Andrew on 11/7/2021.
//

#ifndef MAIN_CPP_TOKENIZER_HPP
#define MAIN_CPP_TOKENIZER_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Token.hpp"

class Tokenizer {
public:
    Tokenizer(std::string nameOfInputFileToTokenize);
    //Tokenizer(std::string nameOfInputFileToTokenize);
    Token *getToken();

    bool isTab(char c);
    bool isColon(char c);
    bool isValidChar(char c);
    bool &wasTab() {return _prevWasTab;}

private:
    std::string nameOfInputFile;
    std::ifstream _inStream;
    bool _prevWasTab = false;

};
#endif //MAIN_CPP_TOKENIZER_HPP
