
#ifndef _TreeNode_hpp
#define _TreeNode_hpp

#include<iostream>
#include<string>
#include "GraphNode.hpp"

//NOTE: TreeNode is a GraphNode. Contains ptr to a GraphNode object 
class GraphNode;

class TreeNode {
public:
    TreeNode( GraphNode *nNode ) : leftSubtree(nullptr), rightSubtree(nullptr), makeNode(nNode) {}

    TreeNode *left(){return leftSubtree;}                // getter [DONE]
    void left( TreeNode *leftPtr ) {leftSubtree = leftPtr;} // setter [DONE]
    TreeNode *right() {return rightSubtree;} //[DONE]
    void right( TreeNode *rightPtr ) {rightSubtree = rightPtr;} //[DONE]
    void print(){makeNode->print();}   // print the value of this node [DONE]
    GraphNode *graphNode() {return makeNode;} //[DONE]

private:
    GraphNode *makeNode;
    TreeNode *leftSubtree, *rightSubtree;
};

#endif
