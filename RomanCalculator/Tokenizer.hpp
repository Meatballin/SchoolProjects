//
// Created by Ali A. Kooshesh on 10/11/21.
//

#ifndef ROMANCALCULATORSTARTER_TOKENIZER_HPP
#define ROMANCALCULATORSTARTER_TOKENIZER_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Token.hpp"

class Tokenizer {
public:
    Tokenizer(std::string nameOfInputFileToTokenize);
    Token *getToken();
    bool isArithmeticOperator(char c);
    bool isRomanChar(char c);
    bool isOperand(char c);

private:
    std::string nameOfInputFile;
    std::ifstream _inStream;
};


#endif //ROMANCALCULATORSTARTER_TOKENIZER_HPP
