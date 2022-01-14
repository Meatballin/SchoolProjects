//
// Created by Ali A. Kooshesh on 2020-01-20.
//

#include<iostream>


#include"Dictionary.hpp"

std::vector<std::tuple<std::string, std::string>> readStartTargetWords(const std::string &inputFileName) {
    std::string word1, word2;
    std::ifstream ladderStream;
    ladderStream.open(inputFileName, std::ios_base::in);
    if( ! ladderStream.is_open()) {
        std::cout << "Unable to open the input file ->" << inputFileName << "<- that contains pairs of words.\n";
        exit(2);
    }
    std::cout << "Successfully opened " << inputFileName << std::endl;
    std::vector<std::tuple<std::string, std::string>> startTargetVector;

    // while there are input lines, do:
    //     read the pair of words into variables, word1, word2
    //     startTargetVector.push_back(make_tuple(word1, word2));
    // end-while

    while(ladderStream >> word1 >> word2)
    {
        startTargetVector.push_back(std::make_tuple(word1, word2));
    }

    return startTargetVector;
}

int main(int argc, char *argv[]) { // the main function.
    if( argc != 3 ) {
        std::cout << "usage: " << argv[0] << " inputFileNameThatContainsDictionary inputFileNameThatContainsPairsOfWords\n";
        exit(1);
    }

    std::ifstream dictionaryStream;
    dictionaryStream.open(argv[1], std::ios_base::in);
    if( ! dictionaryStream.is_open()) {
        std::cout << "Unable to open input file ->" << argv[1] << "<-\n";
        exit(2);
    }
    std::cout << "Successfully opened " << argv[1] << std::endl;
    // we just wanted to make sure that the input file exists. So, close it
    // and let the instance of Dictionary open and use it.
    dictionaryStream.close();

    Dictionary dictionary(argv[1]);
    auto arrayOfPairsToBuildLadders = readStartTargetWords(argv[2]);
    /*for(const auto & [startWord, targetWord]: arrayOfPairsToBuildLadders) {
        std::cout << "start word is " << startWord << "; target word is " << targetWord << std::endl;
    }*/

    std::cout << "\n\n";

    //Testing pathFromTo here
    for(auto & [startWord, targetWord] : arrayOfPairsToBuildLadders)
    {
        std::vector<std::string> pathFromToTest;
        pathFromToTest = dictionary.pathFromTo(startWord, targetWord);
        if(!(pathFromToTest.empty()))
        {
            std::cout << "A ladder for the pair " << startWord << " and " << targetWord << " is: \n";
            for(int j = pathFromToTest.size() - 1; j >= 0; j--)
            {
                std::cout << pathFromToTest.at(j) << "\n";
            }
            std::cout << "\n";

        }
        else
        {
            std::cout << "No ladder for the pair " << startWord << " and " << targetWord << "\n\n";
        }
    }






}



