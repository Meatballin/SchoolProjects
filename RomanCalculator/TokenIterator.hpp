//
// Created by Ali A. Kooshesh on 10/11/21.
//

#ifndef ROMANCALCULATORSTARTER_TOKENITERATOR_HPP
#define ROMANCALCULATORSTARTER_TOKENITERATOR_HPP

#include<vector>
#include "Token.hpp"

class TokenIterator {

public:
    TokenIterator(const std::vector<Token *> &tokens );
    Token  *next();   // provides access to the next token.
    void put_back();  // At times, we will have to look at the next token
    // to know if we can process it or it should be put
    // back so that another entity would use it.

    void printProcessedTokens(); // Prints tokens from the first to the last
    bool hasMoreTokens();  // Do we have at least one more token to dispense?
    ~TokenIterator();

private:
    std::vector<Token  *> tokens;
    int cur, numTokens;
};

#endif //ROMANCALCULATORSTARTER_TOKENITERATOR_HPP
