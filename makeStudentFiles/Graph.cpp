//
// Created by Andrew on 11/17/2021.
//

#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "systemInterface.hpp"

void Graph::parseDepGraph()
{
    std::vector<Token*> tokenVector;
    Tokenizer *tokenizer = new Tokenizer(_fileToMake);
    Token *token = tokenizer->getToken();
    GraphNode *newNode;
    _tree = new MakeTree();
    int counter = 0;
    
    while(!token->eof())
    {
        //creates our vector of tokens before we send it to our function to create our BST and Graph
        createVectorOfTokens(token, tokenVector, tokenizer);
        
        //makes sure we obtain a target from our vector to sent to createGraphAndTree()
        while(!tokenVector.at(counter)->isATarget())
        {
            counter++;
        }

        //if we find our target already in the tree, pass that graphnode, else make a new one
        firstTarget = _tree->find(tokenVector.at(counter)->isTarget());
        if(firstTarget == nullptr)
        {
            newNode = new GraphNode(tokenVector.at(counter)->isTarget());
            createGraphAndTree(tokenVector, _tree, newNode);
        }
        else
        {
            createGraphAndTree(tokenVector, _tree, firstTarget);
        }
        tokenVector.clear();
        counter = 0;
        token = tokenizer->getToken();
    }

    return;
}
//Creates our vector of tokens and passes it back to parseDepGraph()
void Graph::createVectorOfTokens(Token *token, std::vector<Token*> &tokenVector, Tokenizer *tokenizer)
{
    while(!token->eof())
    {
        while(!token->eol())
        {
            if(token->isACommand())
            {
                tokenVector.push_back(token);
                return;
            }
            tokenVector.push_back(token);
            token = tokenizer->getToken();
        } 
        token = tokenizer->getToken();
    }
   return;
    
}

//Searches if our target Token is in our BST at all. If not, it will create that specific graph node
//and add its dependencies to its vector. If we do find our target token, we will only add dependency tokens
//to its dependency vector
void Graph::createGraphAndTree(std::vector<Token*> &vector, MakeTree *tree, GraphNode *name)
{
    long temp;
    GraphNode *newNode;
    tree->insert(name); 
    for(int i = 0; i < vector.size(); i++)
    {
        //If our current index is a target, continue to next iteration of the loop
        if(vector.at(i)->isATarget())
            i++;
    
        if(vector.at(i)->isAName())
        {
            newNode = tree->find(vector.at(i)->isName());
            if(newNode == nullptr)
            {
                newNode = new GraphNode(vector.at(i)->isName());
                if(!timestamp(newNode->getName().c_str(), &temp))
                {
                    std::cerr << "Couldn't stat " << name->getName() << "!\n";
                    exit(1);
                }
                newNode->setTimestamp(temp);
                name->addDependentNode(newNode);
                tree->insert(newNode);
            }
            else
            {
                if(!timestamp(newNode->getName().c_str(), &temp))
                {
                    std::cerr << "Couldn't stat " << name->getName() << "!\n";
                    exit(1);
                }
                newNode->setTimestamp(temp);
                name->addDependentNode(newNode);
                tree->insert(newNode);
            }
        }
        if(vector.at(i)->isACommand())
        {
            name->setCommand(vector.at(i)->isCommandLine());
        }
    }
    //sets timestamps of target files
    
    if(!timestamp(name->getName().c_str(), &temp))
    {
        std::cerr << "Couldn't stat " << name->getName() << "!\n";
        exit(1);
    }
    name->setTimestamp(temp);
    return;
        
}
    
bool Graph::isCyclic(GraphNode *currentNode)
{
    bool tempBool;
    int  index = 0;
    if(currentNode == nullptr)
    {
        std::cout << "You do not have a node to check\n";
        exit(1);
    }
    if(currentNode->onPath())
        return true;

    if(currentNode->dependentNodes()->empty())
    {
        currentNode->onPath(false);
        return false;
    }
    
    currentNode->onPath(true);
    while(index < currentNode->numDependentNodes())
    {
        tempBool = isCyclic(currentNode->dependentNodes()->at(index));
        if(tempBool)
        {
            return true;
        }
        index++;
    }
    return false;

}

 void Graph::runMake() 
{
     runMakeHelper(_tree->getRoot()->graphNode()->dependentNodes());
     createXFile(_tree->getRoot()->graphNode());
     return;
}

void Graph::runMakeHelper(std::vector<GraphNode*> *vector)
{
    for(int i = 0; i < vector->size(); i++)
    {
        createObjectFiles(vector->at(i));
    }
    
}

//This function will execute all .o file command lines
void Graph::createObjectFiles(GraphNode *node)
{
    int index = 0;
    if(node->dependentNodes()->empty())
    {
        return;
    }
    while(index < node->dependentNodes()->size())
    {
        createObjectFiles(node->dependentNodes()->at(index));
        if(node->getTimestamp() < node->dependentNodes()->at(index)->getTimestamp())
        {
            node->runCommand();
            long time = 0;
            if(!timestamp(node->getName().c_str(), &time))
            {
                std::cout << "File is corrupted...\n";
                exit(1);
            }
            node->setTimestamp(time);
        }
        index++;
    }
    return;
}

//After all .o's are created, this function will test if any of the .o timestamps are > the .x file. If so, compile .x command line
void Graph::createXFile(GraphNode *node)
{
    for(int i = 0; i < node->dependentNodes()->size(); i++)
    {
        if(node->getTimestamp() < node->dependentNodes()->at(i)->getTimestamp())
        {
            node->runCommand();
            return;
        }
    }
}
