
#ifndef _Graph_hpp
#define _Graph_hpp

#include<iostream>
#include<cstring>

#include "MakeTree.hpp"
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "GraphNode.hpp"
class Graph {
public:
    Graph( std::string name ) {_fileToMake = name;}//pass to _fileToMake [DONE]
    void print() {_tree->print();} //[DONE]
    void parseDepGraph(); //Calls tokenizer and puts the values into the binary tree. Does not include colon, eol, \t [DONE]
     //runmake() starts at root, go down and set timestamps on the way up. IF timestamps is higher than previous
    //nodes, then we have to run the command 
    void runMake();//DONE
    bool isCyclic() {return isCyclic(_tree->getRoot()->graphNode());}//if onpath is true, graph is cyclic [DONE]
    GraphNode *getTarget() {return firstTarget;} //[DONE]
    MakeTree *getTree() {return _tree;} //[DONE]

private:
    bool isCyclic(GraphNode *node);
    void createVectorOfTokens(Token *token, std::vector<Token*> &vector, Tokenizer *tokenizer);
    void createGraphAndTree(std::vector<Token*> &vector, MakeTree *tree, GraphNode *firstTarget);
    void runMakeHelper(std::vector<GraphNode *> *vector);
    void createObjectFiles(GraphNode *node);
    void createXFile(GraphNode *node);
private:
    std::string _fileToMake, _targetToMake;
    GraphNode *firstTarget;
    MakeTree *_tree;  // MakeTree implements a binary-search tree similar to BinSearchTree
};

#endif
