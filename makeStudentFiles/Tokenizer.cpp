//
// Created by Andrew on 11/7/2021.
//
#include <iostream>
#include "Tokenizer.hpp"
#include <string>


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
    Token *token = new Token; 
    //If _prevWasTab is set to true, we know our next token should be a command line
    if(wasTab())
    {
        token->isACommand() = true;
        std::string commandLine;
        getline(_inStream, commandLine, '\n');
        token->isCommandLine() = commandLine;
        wasTab() = false;
        return token;
    }
    while(_inStream.get(c) && c != '\n' && isspace(c))
    {
        if(isTab(c))
        {
            token->variable() = c;
            //set bool to true in Tokenizer so we know on next getToken that
            //we have a command line. After we get command, set it back to false
            wasTab() = true;
            return token;
        }
    }

    //EOF
    if(_inStream.eof())
    {
        token->eof() = true;
        return token;
    }
    //EOL
    else if(c == '\n')
    {
        token->eol() = true;
        return token;
    }
    if(isColon(c))
    {
        token->variable() = c;
        return token;
    }
    //This will grab our names or targets from the input stream and tokenize them
    else if(isValidChar(c))
    {
        std::string name;
        name += c;
        while(isValidChar(c))
        {
            _inStream.get(c);
            if(isspace(c))
                break;
            //We know it's a target
            if(isColon(c))
            {
                _inStream.putback(c);
                token->isTarget() = name;
                token->isATarget() = true;
                return token;

            }
            name += c;
        }
        //returns name in the token
        token->isName() = name;
        token->isAName() = true;
        return token;
    }
    else
    {
        std::cout << "Encountered an unknown character -> " << c
        << "<- in getToken. Terminating... " << std::endl;
        exit(1);
    }
    return token;

}

//returns true if we have run into a colon on input stream
bool Tokenizer::isColon(char c)
{
    return c == ':';
}
//returns true if we have run into a tab on input stream
bool Tokenizer::isTab(char c)
{
    return c == '\t';
}

//returns true if any character except \n and tab
bool Tokenizer::isValidChar(char c)
{
    return !isspace(c) && c != '\n' && !isTab(c);
}






