#include <iostream>
#include "Token.hpp"
#include "InfixToPostfix.hpp"
#include "Tokenizer.hpp"
#include <map>
#include <stack>

void convertToPostFix(const std::vector<Token *> &assignmentStatement, std::string &total
                      ,std::map<char, std::string> &symbolTable);
std::string calculation(const std::vector<Token *> &postfixTokens, std::map<char, std::string> &symbolTable);

int main(int argc, char *argv[]) {

    // create a tree and then print the values of its nodes
    // from the smallest to the largest.
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(1);
    }
    inputStream.close();
    Tokenizer tokenizer = Tokenizer(argv[1]);
    std::vector<Token *> assignmentStatement;
    Token *token = tokenizer.getToken();
    std::map<char, std::string> symbolTable;
    std::string total;
    while( ! token->eof() ) {
        //starts to create vector of tokens
        assignmentStatement.push_back(token);
        //If we are at eol, print out operand and "equals" before we do calculations
        if(token->eol()) {
            std::cout << assignmentStatement.at(0)->variable();
            if(assignmentStatement.at(1)->isEqualSign())
            {
                std::cout << " equals ";
            }
            //convert to postfix function, passing our infix vector and our map so we can
            //update it with new values.
            convertToPostFix(assignmentStatement, total, symbolTable);
            std::cout << total << std::endl;
            symbolTable.insert(std::pair<char, std::string>(assignmentStatement.at(0)->variable(), total));
            assignmentStatement.clear();
        }
        token = tokenizer.getToken();
    }
    return 0;
}

void convertToPostFix(const std::vector<Token *> &assignmentStatement, std::string &total
                      ,std::map<char, std::string> &symbolTable)
{
    InfixToPostfix *itop = new InfixToPostfix();
    std::vector<Token *> postfixTokens;
    std::vector<Token *> tokens;

    //start at i = 2 because we don't need 'char' and '=' in our postfix
    for( int i = 2; i < assignmentStatement.size(); i++ )
        tokens.push_back(assignmentStatement.at(i));
    //Convert to postfix. Write a function that will compute what we need to.
    itop->convert( tokens, postfixTokens );
    //Call for our calculation with our postfix vector. Update our reference to our string in main
    //Will use this "total" to place in our map along with our operand
    total = calculation(postfixTokens, symbolTable);
    return;
}

//This function will take as an argument our postfix vector
//Makes sure our roman numbers are valid. Does the postfix calculation
//returns a string to caller, and that will update our string in main
std::string calculation(const std::vector<Token *> &postfixTokens, std::map<char, std::string> &symbolTable)
{
    std::stack<std::string> romanNumerals;
    //Iterate through every token of our postfix vector
    for(auto token : postfixTokens)
    {
        //If we have a valid roman number or an operand enter here
        if(token->isRomanNumber() || (token->variable() >= 'a' && token->variable() <= 'z'))
        {
            //If we find an operand, search our map if it isn't empty so we can pull
            //a previously stored roman numeral out from it. Push it onto stack after
            if((token->variable() >= 'a' && token->variable() <= 'z') && !symbolTable.empty())
            {
                std::string iterator = symbolTable.find(token->variable())->second;
                romanNumerals.push(iterator);
            }
            //Need to make sure our roman numerals are valid before doing calculations
            else if(token->isAValidRomanNumber(token->romanNumber()))
            {
                romanNumerals.push(token->romanNumber());
            }
            else
            {
                std::cout << "One of your roman numerals are not a valid roman numeral\n";
                exit(1);
            }
        }
        else
        {
            std::string second = romanNumerals.top();
            //Check if we only have one roman numeral on our postfix expression
            //If this is the case, we have no calculation to do
            if(romanNumerals.empty())
            {
                return second;
            }
            romanNumerals.pop();
            std::string first = romanNumerals.top();
            romanNumerals.pop();
            //At this point, we should have two valid roman numerals in our tokens before doing calculations.
            //Turn them both into decimals, make calculation, turn them back into roman numerals, then push back
            //onto stack
            int secondToDecimal = token->romanToDecimal(second);
            int firstToDecimal = token->romanToDecimal(first);
            int total = 0;

            //Deal with all of our operations
            if(token->isAdditionOperator())
            {
                total = secondToDecimal + firstToDecimal;
                //check if we go out of range for this addition
                if((total <= 3999))
                {
                    romanNumerals.push(token->decimalToRoman(total));
                }
                else
                {
                    std::cout << "Value for addition operation is out of scope!\n";
                    exit(1);
                }

            }
            else if(token->isSubtractionOperator())
            {
                total = firstToDecimal - secondToDecimal;
                if(total >= 0)
                {
                    romanNumerals.push(token->decimalToRoman(total));
                }
                else
                {
                    std::cout << "Value for subtraction ended up negative!\n";
                    exit(1);
                }

            }
            else if(token->isDivisionOperator())
            {
                total = secondToDecimal / firstToDecimal;
                romanNumerals.push(token->decimalToRoman(total));
            }
            else if(token->isModuloOperator())
            {
                total = secondToDecimal % firstToDecimal;
                romanNumerals.push(token->decimalToRoman(total));
            }
            else if(token->isMultiplicationOperator())
            {
                total = secondToDecimal * firstToDecimal;
                romanNumerals.push(token->decimalToRoman(total));
            }
            else
            {
                std::cout << "Expected an arithmetic operator instead found the following token." << std::endl;
                token->print();
                exit(1);
            }
        }
    }
    //At this point, the top of our stack should hold our total value
    return romanNumerals.top();
}



