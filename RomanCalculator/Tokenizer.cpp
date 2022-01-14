//
// Created by Ali A. Kooshesh on 10/11/21.
//

#include <iostream>
#include "Tokenizer.hpp"
#include <string>
#include <utility>


//This function will be responsible for creating all of the tokens we need. If
//we analyze that we have found a roman numeral or a decimal, we need to
//call the functions from our RomanNumber class to make proper conversions


Tokenizer::Tokenizer(std::string nameOfInputFileToTokenize): nameOfInputFile{nameOfInputFileToTokenize}
{
    _inStream.open(nameOfInputFile, std::ios::in);
}

Token* Tokenizer::getToken()
{
    if(!_inStream.is_open())
    {
        std::cout << "There is no input file!\n";
        exit(1);
    }
    char c;
    while(_inStream.get(c) && c != '\n' && isspace(c))
    {
    }
    Token *token = new Token;
    //if we are end of file
    if(_inStream.eof()){

        token->eof() = true;
    }
    //if end of line
    else if(c == '\n')
    {
        token->eol() = true;
    }
    //if we find a roman numeral character
    else if(isRomanChar(c))
    {
        //Add our current .get character to our roman string because we know it's
        //a roman character
        std::string roman;
        roman += c;
        //Loop and check other inputs on our file stream. If they are roman numerals
        //keep adding it to our string. If not, we have to put it back onto the stream.
        while(1)
        {
            _inStream.get(c);
            if(isRomanChar(c))
            {
                roman += c;
            }
            else
            {
                _inStream.putback(c);
                break;
            }
        }
        //Set our finished string in Token class.
        token->romanNumber(roman);
    }
    // if we find an operator or operand, set the _symbol in Token class
    else if(isArithmeticOperator(c) || isOperand(c))
    {
        token->variable() = c;
    }
    else
    {
        std::cout << "Encountered an unknown character -> " << c
        << "<- in getToken. Terminating... " << std::endl;
        exit(1);
    }
    return token;

}
bool Tokenizer::isRomanChar(char c)
{
    return c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M';
}

bool Tokenizer::isOperand(char c)
{
    if((c >= 'a' && c <= 'z'))
    {
        return true;
    }
    return false;
}
bool Tokenizer::isArithmeticOperator(char c)
{
    return c == '+' || c == '/' || c == '*' || c == '-' || c == '%' || c == '(' || c == ')' || c == '=';
}


