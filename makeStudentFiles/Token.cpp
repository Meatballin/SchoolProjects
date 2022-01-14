//
// Created by Andrew on 11/7/2021.
//

#include <iostream>
#include "Token.hpp"


void Token::print() {
    if( eol()                           )  std::cout << "eol";
    else if( eof()                      )  std::cout << "EOF\n" ;
    else if(isTab()                     )  std::cout << "TAB";
    else if(isColon()                   )  std::cout << ": ";
    else if(isACommand()                )  std::cout << isCommandLine();
    else if(isATarget()                 )  std::cout << isTarget();
    else if(isAName()                   )  std::cout << isName();
    else {
        std::cout << "\n\nToken::print -- Came across an unknown token. Terminating...\n";
        exit(1);
    }
    
}

//initializes our private member variables in Token class to placeholder values
void Token::init() {
    _commandLine = _targetToken = "";
    _eof = _eol = _isTarget = _isCommandLine = false;
    _symbol = '\0';
}

