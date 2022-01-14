#ifndef _GRAPHNODE_HPP
#define _GRAPHNODE_HPP

#include<iostream>
#include<string>
#include<vector>
#include "systemInterface.hpp"
#include "Token.hpp"
//How to determine if a graph has a cycle or not:

class GraphNode {
public:
    GraphNode( std::string name ) {_name = name; _listOfDependentNodes = new std::vector<GraphNode *>;} //Constructor sets our _name variable with token name [DONE]
    std::string getName() {return _name;}; //Returns _name [DONE]
    void setName( std::string name ) {_name = name; return;} //sets _name [DONE]
    void setTimestamp(int ts) {_timestamp = ts; return;} //sets _timestamp [DONE]
    int getTimestamp() {return _timestamp;} //returns _timestamp [DONE]
    std::vector<GraphNode *> *dependentNodes() {return _listOfDependentNodes;} //returns the vector of the node [DONE]
    void setCommand(std::string cmnd) {_command = cmnd;} //sets _command [DONE]
    std::string getCommand() {return _command;} //returns _command [DONE]
    void runCommand() {executeCommand(_command.c_str()); return;} // execute the command associated with this node. Only for target nodes. [DONE]
    void addDependentNode(GraphNode *child) {_listOfDependentNodes->push_back(child);} //ptr to a graphnode that adds it to the vector [DONE]
    bool onPath() {return _onPath;} //helps catch cycles in the graph [DONE]
    void onPath(bool v) {_onPath = v; return;} //sets _onPath [DONE]
    bool wasMade() {if(_wasMade = true) return true; else return false;}//returns was the graph node created or not [DONE]
    void wasMade(bool v){_wasMade = v;} //Sets _wasMade [DONE]
    bool isATarget(); //returns true if our graph node is considered a target [DONE]
    void isATarget(bool v) {_isATarget = v; return;} //Sets _isATarget [DONE]
    int numDependentNodes() {return dependentNodes()->size();} //returns size of vector of current graphNode [DONE]
    void print(); // [DONE]

private:
    std::string _name, _command;
    int _timestamp = 0;
    std::vector<GraphNode *> *_listOfDependentNodes;// pointer to the vector that has the list of the 
    //dependent nodes

    bool _onPath, _isATarget, _wasMade;
};

#endif
