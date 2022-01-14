//
// Created by Ali A. Kooshesh on 10/11/21.
//

#ifndef ROMANCALCULATORSTARTER_TOKEN_HPP
#define ROMANCALCULATORSTARTER_TOKEN_HPP

#include <vector>
#include <string>
#include "RomanNumber.hpp"

/*

    This class represent the notion of a token; the building blocks of
    Roman expressions. In this context, a token either represents an
            operator (the addition, subtraction, multiplication, division, or
    modulo arithmetic operators), open or close parentheses, a variable, or a Roman
    number.

    To create a token, you pass an argument to it that characterizes the token.
    For example, to create a token to represent the addition operator, you would do:

    Token *tok = new Token('+'); // create a token to represent the addition op.

    However, for certain tokens, (eof, eol, variable) you will have to create a token
    first and set it later.

    Token *tok = new Token();  // an uninitialized token
    tok->eof(true);            // make it represent EOF token.

*/


class Token: public RomanNumber {

public:
    //Note: Init is just to initialize all private variables with default vals of the Token class
    //when either of the three constructors is called
    Token() { init(); }
    Token(char c) { init(); _symbol = c; }
    Token(const std::string &s) {
        init();
        _romanNumber = s;
    }

    //returns the string of our Roman Numberal number
    std::string romanNumber() const     { return _romanNumber; }
    //setter function for our Roman Numeral string
    void romanNumber(const std::string &str ) { _romanNumber = str; }

    //Getter and setter of eof and eol
    bool &eof()  { return _eof; }
    bool &eol()  { return _eol; }

    //checks for open and clothes paranthesis, returns true if they exist, false otherwise
    bool isOpenParen() const  { return _symbol == '('; }
    bool isCloseParen() const { return _symbol == ')'; }

    //Checks our current token for each of these operators/operands
    bool isEqualSign() const              { return _symbol == '='; }
    bool isMultiplicationOperator() const { return _symbol == '*'; }
    bool isAdditionOperator() const       { return _symbol == '+'; }
    bool isSubtractionOperator() const    { return _symbol == '-'; }
    bool isModuloOperator() const         { return _symbol == '%'; }
    bool isDivisionOperator() const       { return _symbol == '/'; }
    bool isAVariable() const              { return _symbol >= 'a' && _symbol <= 'z'; }
    char &variable()                      { return _symbol; }

    bool isRomanNumber() const;

    //prints whatever symbol our token currently holds
    void print();

private:
    void init();

    std::string _romanNumber;
    bool _eof, _eol;
    char _symbol;
};

#endif //ROMANCALCULATORSTARTER_TOKEN_HPP
