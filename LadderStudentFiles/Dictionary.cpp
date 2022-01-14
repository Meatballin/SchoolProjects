//
// Created by Ali A. Kooshesh on 2020-01-19.
//

#include <iostream>
#include <fstream>
#include "Dictionary.hpp"


Dictionary::Dictionary(std::string inputFileName) {
    // open inputFileName and store its contents, which is a collection of
    // words, one per line, in vector, "words".
    dictionaryStream.open(inputFileName);
    std::string word;
    while (dictionaryStream >> word)
    {
        words.push_back(word);
    }

    std::cout << "Creating an instance of Dictionary with input file: " << inputFileName << std::endl;
}

int Dictionary::idxOfSuccessorWordFrom(std::string word, int fromIdx)
{
    int tempInt = positionalDiff(word, words.at(fromIdx));
    if(tempInt != 1)
    {
        return words.size();
    }
    else
    {
        return fromIdx;
    }
}
std::vector<std::string> Dictionary::neighborsOf(std::string someWord)
{
    std::vector<std::string> result;
    //use tempInt to find out of if positionalDiff has found a neighbor
    int tempInt;

    //Set "someWord" as the first item in the vector before searching for
    //the neighboring words in the dictionary
    result.push_back(someWord);

    //loop with positionalDiff to find out which words are neighbors
    // to the string "someWord" in the argument of this function.
    for(int index = 0;index < words.size(); index++)
    {
        tempInt = positionalDiff(someWord, words.at(index));
        if(tempInt == 1)
        {
            result.push_back(words.at(index));

        }

    }
    //These lines of code execute when we do not find a neighbor in the dictionary
    return result;
}

int Dictionary::positionalDiff(std::string word1, std::string word2)
{
    //start at 4 and subtract per different character in the null terminated char array(string)
    int numOfDifferentChars = 4;
    int index = 0;

    //traverse string and if one character is not identical to the other subtract one from total
    for(; index <= 3; index++)
    {
        if(word1[index] == word2[index])
        {
            numOfDifferentChars--;
        }
    }
    return numOfDifferentChars;


}

int Dictionary::member(std::string wordToFind)
{
    for(int i = 0; i <= words.size(); i++)
    {
        if(wordToFind == words[i])
        {
            return i;
        }
    }
    return words.size();
}
int Dictionary::size()
{
    return words.size();
}
void Dictionary::printDictionary()
{
    for(int i = 0; i <= words.size(); i++)
    {
        std::cout << words[i] << "\n";
    }
}

std::vector<std::string> Dictionary::pathFromTo(std::string from, std::string to)
{
    //Create vector that this function will return to main with completedLadder
    std::vector<std::string> completedLadder;

    //tuple used to store previous values of stack, and also used in storing
    //strings into "completedLadder" at end of function before return
    std::tuple <std::string, int> tempTuple;
    //set all booleans in "used" to False
    for(int i = 0; i < words.size(); i++)
    {
        used.push_back(false);
    }

    //push first string and index onto the stack as a tuple
    ladder.push(std::make_tuple(from,member(from)));
    //set the index of first string to true in "used"
    used.at(member(from)) = true;

    //variables
    int index = 0;
    int storeIndex = 0;
    std::string previousString;

    //while stack is not empty, find next neighbor
    while(!ladder.empty())
    {
        //We will reach here after breaking out of "for" loop to then break
        //out of our while loop and return out either empty or completed vector
        if(from == to)
        {
            break;
        }
        for(; index < words.size(); index++)
        {
            //search for index of a proper neighbor
            storeIndex = idxOfSuccessorWordFrom(from, index);

            //check if index is anything but max dictionary size.
            //if this is the case, drop into this if statement and check if
            //the same index is true or false on the "used" vector
            if(storeIndex != words.size())
            {
                //if proper neighbor is found, push it to the stack
                if(!used.at(storeIndex))
                {
                    from = words.at(storeIndex);
                    ladder.push(std::make_tuple(from, storeIndex));
                    used.at(storeIndex) = true;
                    index = 0;
                }

            }
            //Check if we have reached our goal and break out of our "for" loop
            if(from == to)
            {
                break;
            }

            //If index is one less than the size of our words vector, this means we haven't found a
            //neighbor for our current string, and we have to pop off the stack
            if(index == words.size() - 1)
            {
                //using this to save current index of string before it's popped off stack
                tempTuple = ladder.top();
                index = std::get<1>(tempTuple);
                if(!ladder.empty())
                {
                    ladder.pop();
                }
                //if ladder is empty, return an empty vector
                if(ladder.empty())
                {
                    return {};
                }
                //using this to obtain previous string to research through dictionary with previous index as well
                tempTuple = ladder.top();
                from = std::get<0>(tempTuple);
            }

        }
    }
    //store ladder onto our vector to be returned to main
    while(!ladder.empty())
    {
        tempTuple = ladder.top();
        completedLadder.push_back(std::get<0>(tempTuple));
        ladder.pop();
    }
        //set used vector back to false before next function call
        used.clear();
        //return completed ladder as a vector to main
        return completedLadder;
}
Dictionary::~Dictionary() {
    // close the input stream if it was successfully opened.
    if(dictionaryStream.is_open())
        dictionaryStream.close();
}
