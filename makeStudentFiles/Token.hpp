//
// Created by Andrew on 11/7/2021.
//

#ifndef MAIN_CPP_TOKEN_HPP
#define MAIN_CPP_TOKEN_HPP

#include <iostream>

class Token{

public:

    Token() { init(); }
    Token(char c) { init(); _symbol = c; }
    Token(bool b) { init(); _isCommandLine = b; }
    Token(const std::string &s) {
        init();
    }

    //Getter and setter of eof and eol
    bool &eof()  { return _eof; }
    bool &eol()  { return _eol; }
    std::string &isTarget() { return _targetToken; }
    std::string &isCommandLine() { return _commandLine;}
    std::string &isName() {return _name;}
    bool isTab() const { return _symbol == '\t'; }
    bool isColon()const { return _symbol == ':';}
    bool &isACommand() {return _isCommandLine;}
    bool &isATarget()  {return _isTarget;}
    bool &isAName()    {return _isName; }

    char &variable()   { return _symbol; }

    void print();

private:
    void init();
    std::string _name;
    std::string _targetToken;
    std::string _commandLine;
    bool _eof = false,_eol = false, _isTarget = false, _isCommandLine = false, _isName = false;
    char _symbol;
};


#endif //MAIN_CPP_TOKEN_HPP
