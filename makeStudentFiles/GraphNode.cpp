//
// Created by Andrew on 11/14/2021.
//

#include <iostream>
#include "GraphNode.hpp"

void GraphNode::print()
{
    std::cout << getName();
}

 bool GraphNode::isATarget()
 {
    if(_isATarget)
        return true;
    return false;
 }
