//
// Created by Andrew on 10/14/2021.
//
#include <iostream>
#include <string>
#include "RomanNumber.hpp"

bool RomanNumber::isAValidRomanNumber(std::string romanNumber)
{
    return romanNumber == decimalToRoman(romanToDecimal(romanNumber));
}

std::string RomanNumber::decimalToRoman(int decimalNumber)
{

    if(decimalNumber > 4000 || decimalNumber < 0)
    {
        std::cout << "Roman number is out of range!\n";
        exit(1);
    }
    //String that we will be returning to caller
    std::string romanString;
    //Need integer variable to keep track of our division results as we
    //figure out how many roman characters we need to tack onto romanString.
    int tracker;
    int index;
    if(decimalNumber >= 1000)
    {
        tracker = (decimalNumber / 1000);
        //
        for(index = 0; index < tracker; index++)
        {
            romanString.append("M");
        }
        //We need to keep track of the remainder after this if statement
        decimalNumber %= 1000;
    }
    //Checking to see if our decimal is over 100
    if(decimalNumber >= 100)
    {
        tracker = (decimalNumber / 100);
        //If our value was >=900 and < 1000
        if(tracker == 9)
        {
            romanString.append("CM");
        }
        //Need at least 1 'D' if we are >= 5 in our division and less than 9
        else if(tracker >= 5)
        {
        romanString.append("D");
            for(index = 0; index < tracker - 5; index++)
            {
                romanString.append("C");
            }
        }
        //If exactly 400
        else if(tracker == 4)
        {
            romanString.append("CD");
        }
        else if(tracker >= 1)
        {
            for(index = 0; index < tracker; index++)
            {
                romanString.append("C");
            }
        }
        //after we pass these if's we still need to find remainder of what we have left
        decimalNumber %= 100;
    }
    //Checking to see if our decimal is over 10
    if(decimalNumber >= 10)
    {
        tracker = (decimalNumber / 10);
        //if we get 90
        if(tracker == 9)
        {
            romanString.append("XC");
        }
        //if we are over 50
        else if(tracker >= 5)
        {
            romanString += 'L';
            for(index = 0; index < tracker - 5; index++)
            {
                romanString.append("X");
            }
        }
        //if we had 40 at this point
        else if(tracker == 4)
        {
            romanString.append("XL");
        }
        //If we are over 10 at this point
        else if(tracker >= 1)
        {
            for(index = 0; index < tracker; index++)
            {
                romanString.append("X");
            }
        }
        decimalNumber %= 10;
    }

    if(decimalNumber >= 1)
    {
        tracker = decimalNumber;
        //If we have 9
        if(tracker == 9)
        {
            romanString.append("IX");
        }
        //If we have 5
        else if(tracker >= 5)
        {
            romanString.append("V");
            for(index = 0; index < tracker - 5; index++)
            {
                romanString.append("I");
            }
        }
        //If we have 4
        else if(tracker == 4)
        {
            romanString.append("IV");
        }
        //Else tack on I's for our 1's
        else if(tracker >= 1)
        {
            for(index = 0; index < tracker; index++)
            {
                romanString.append("I");
            }
        }
    }
    return romanString;
}


//This function should get passed the roman numeral string inside of our Token class once it
//has retrieved it.
int RomanNumber::romanToDecimal(std::string romanNumber)
{
    //set endOfStringIdx to last roman numeral of our entire string
    int endOfStringIdx = romanNumber.size() - 1;

    //Use these for comparisons of our roman values to figure out if
    //we need to subtract from our total or not
    int total = 0;
    int previous = 0;
    for(int i = endOfStringIdx; i >= 0; i--)
    {
        //If our value at end of roman numeral string is less than it's previous
        //we need to subtract it from our total.
        if(romanToDecimalHelper(romanNumber[i]) >= previous)
        {
            total = total + romanToDecimalHelper(romanNumber[i]);
        }
        else
        {
            total = total - romanToDecimalHelper(romanNumber[i]);
        }
        previous = romanToDecimalHelper(romanNumber[i]);

    }
    return total;
}

int RomanNumber::romanToDecimalHelper(char romanChar){
    switch(toupper(romanChar))
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}
