//
// Created by Andrew on 11/14/2021.
//
#include <iostream>
#include "MakeTree.hpp"
#include <string.h>


GraphNode* MakeTree::find( std::string name )
{
    return findHelper(name, _root);
}
GraphNode* MakeTree::findHelper(std::string name, TreeNode* root)
{
    if(root == nullptr)
    {
        return nullptr; 
    }
    if(strcmp(name.c_str(), root->graphNode()->getName().c_str()) == 0)
    {   
        return root->graphNode();
    }
    if(strcmp(name.c_str(), root->graphNode()->getName().c_str()) > 0)
    {
        return findHelper(name, root->right());
    }
    if(strcmp(name.c_str(), root->graphNode()->getName().c_str()) < 0)
    {
        return findHelper(name, root->left());
    }
    return root->graphNode();
}

void MakeTree::insert( GraphNode *nNode )
{
    _root = insert(_root, nNode); 
    
}
TreeNode* MakeTree::insert(TreeNode *tNode, GraphNode *nNode)
{
    //If we have no root for our BST, create it and point to our first graphnode
    if(tNode == nullptr)
    {
        return new TreeNode(nNode);
    }
        
    if(strcmp(nNode->getName().c_str(), tNode->graphNode()->getName().c_str()) < 0)
    {
        tNode->left(insert(tNode->left(), nNode));
    }
    else if(strcmp(nNode->getName().c_str(), tNode->graphNode()->getName().c_str()) > 0)
    {
        tNode->right(insert(tNode->right(), nNode));
    }
    return tNode;
}

//print tree with inorder traversal
void MakeTree::print(TreeNode *root)
{
    if(root == nullptr)
        return;
    print(root->left());
    std::cout << root->graphNode()->getName() << " timestamps: " << root->graphNode()->getTimestamp() <<  std::endl;
    print(root->right());
}