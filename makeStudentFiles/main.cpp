#include <iostream>
#include <cstdlib>
#include <vector>
#include "Graph.hpp"
#include "Token.hpp"
#include "Tokenizer.hpp"

int main(int argc, const char *argv[] ) 
{
    //NOTES FOR PROJECT:
    //Timestamp of target has to be larger than the files that depend on it. 
    //If a file does not exist, it is as good as the timestamp that is  old
    //MakeTree is a BST. Ask tree first if you've seen the name of the file or not
    //if not, create a graph node, else don't. 
    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " name-of-a-makefile\n";
        exit(1);
    }

    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(1);
    }
    
    inputStream.close();
    Tokenizer tokenizer = Tokenizer(argv[1]);
    Token *token = tokenizer.getToken();
    MakeTree *makeTree = new MakeTree();

    // creates a Reader and build the dependency graph using the tokens that it returns.
    Graph *make = new Graph(argv[1]);
   
    make->parseDepGraph();
    //make->getTree()->print();
    if( make->isCyclic())  {
        std::cerr << "Input graph has cycles.\n";
        exit(1);
    }
    make->runMake();
    // make->getTree()->print();
    return 0;
}
