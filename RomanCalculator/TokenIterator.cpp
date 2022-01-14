//
// Created by Ali A. Kooshesh on 10/11/21.
//

#include "TokenIterator.hpp"

TokenIterator::TokenIterator(const std::vector<Token *> &tokens )
{
    this->tokens = tokens;
    numTokens = tokens.size();
    cur = 0;
}

TokenIterator::~TokenIterator()
{
    // Do not delete tokens as it is a borrowed pointer!
}

Token  *TokenIterator::next()
{
    return hasMoreTokens() ? tokens.at(cur++) : nullptr;
}

void TokenIterator::put_back()
{
    --cur;
}

void TokenIterator::printProcessedTokens()
{
    for( int i = 0; i < cur; i++ )
        tokens.at(i)->print();
}

bool TokenIterator::hasMoreTokens()
{
    return cur != numTokens;
}
