//
// Created by Andrew on 10/14/2021.
//

#ifndef INFIXTOPOSTFIX_CPP_ROMANNUMBER_HPP
#define INFIXTOPOSTFIX_CPP_ROMANNUMBER_HPP

#include <iostream>


class RomanNumber {
public:
    //Function that determines if the inputted roman number is valid or not
    bool isAValidRomanNumber(std::string romanNumber);

    //Converts a decimal integer to a roman number, returns the string
    std::string decimalToRoman(int decimalNumber);

    //Converts our roman number string to a decimal and returns the integer
    int romanToDecimal(std::string romanNumber);

    //Helper function for returning the values of each different roman numeral as an integer
    int romanToDecimalHelper(char romanChar);

};


#endif //INFIXTOPOSTFIX_CPP_ROMANNUMBER_HPP
