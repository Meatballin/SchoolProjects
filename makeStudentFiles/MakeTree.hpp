
#ifndef _MakeTree_hpp
#define _MakeTree_hpp

#include<iostream>
#include<string>

#include "TreeNode.hpp"

class MakeTree {
public:
    MakeTree() {_root == nullptr;} //[DONE]
    void insert( GraphNode *nNode ); //[DONE]
    GraphNode *find( std::string name ); //[DONE]
    void print() { print(_root); }   // print the tree using in-order traversal [DONE]
    TreeNode  *getRoot() { return _root; } //[DONE]

private:
    GraphNode *findHelper(std::string name, TreeNode* _root); //[DONE]
    TreeNode *insert(TreeNode *tNode, GraphNode *nNode); //[DONE]
    void print(TreeNode *root); //[DONE]
    
    TreeNode *_root;
};

#endif
