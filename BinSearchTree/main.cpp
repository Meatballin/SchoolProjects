#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main( int argc, char *argv[] ) {
// create a tree and then print the values of its nodes
// from the smallest to the largest.

BinSearchTree *tree = new BinSearchTree();
BinSearchTree *newTree = new BinSearchTree();
BinSearchTree *tempIntersectTree = new BinSearchTree();
BinSearchTree *tempUnionTree = new BinSearchTree();
BinSearchTree *tempDifferenceOfTree = new BinSearchTree();
    int v;

    std::cout << "Insert values into the tree and type \"0\" when finished\n";
    while( std::cin >> v )
    {
        if(v == 0)
        {
            break;
        }
        tree->insert( v );

    }
    std::cout << "\n";

    /*//Test for find() function
    std::cout << "Test for find() function:\n";
    bool testBool;
    std::cin >> v;
    testBool = tree->find(v);
    std::cout << testBool << "\n\n";


    //Test for iterFind() function
    std::cout << "Test for iterFind() function:\n";
    std::cin >> v;
    testBool = tree->iterFind(v);
    std::cout << testBool << "\n\n";


    //Test for size()
    std::cout << "Test for size() function:\n";
    v = tree->size();
    std::cout << v << "\n\n";


    std::cout << "Inorder Dump: \n";
    tree->inorderDump();
    std::cout << "\n\n";

    //Test for maxDepth()
    std::cout << "Test for maxDepth():\n";
    v = tree->maxDepth();
    std::cout << v;*/


    //Test for levelOrderDump
    //tree->levelOrderDump();
    //std::cout << "\n\n";
    int removeVariable;
    while(tree->size() != 0)
    {
        std::cin >> removeVariable;
        std::cout << "Please enter an integer to remove from our tree: \n";
        tree->remove(removeVariable);
        tree->levelOrderDump();
    }


   /* int k;
    std::cout << "Please enter an integer k to find the kth smallest element in the BST: ";
    std::cin >> k;
    std::cout << tree->kthSmallest(k);*/

   /*int k;
   std::cout << "Please enter an integer k to print the kth level of the BST: ";
   std::cin >> k;
   tree->valuesAtLevel(k);*/

    /*int level;
    std::cout << "Please enter which level of the tree you would like printed out: ";
    std::cin >> level;
   tree->iterValuesAtLevel(level);*/

//    std::cout << "Please enter a root to leaf sum you are looking for in the BST: ";
//    int rootToLeafSum;
//    std::cin >> rootToLeafSum;
//    if(tree->hasRootToLeafSum(rootToLeafSum))
//        std::cout << "Your sum was found in the tree!\n";
//    else
//        std::cout << "Your sum was not found in the tree...\n";

//    std::cout << "Insert values into the NEW TREE and type \"0\" when finished\n";
//    while(std::cin >> v)
//    {
//        if(v == 0)
//        {
//            break;
//        }
//        newTree->insert( v );
//
//    }
//    std::cout << "\n";
//
//     std:: cout << tree->areIdentical(newTree);

//    Test for intersectWith
//    std::cout << "Test for intersection!\n";
//    tempIntersectTree = tree->intersectWith(newTree);
//    tempIntersectTree->inorderDump();

    /*//Test for unionWith
    std::cout << "Test for unionWith!\n";
    tempUnionTree = tree->unionWith(newTree);
    tempUnionTree->inorderDump();*/

    /*//Test for differenceOf
    std::cout << "Test for differenceOf!\n";
    tempDifferenceOfTree = tree->differenceOf(newTree);
    tempDifferenceOfTree->inorderDump();*/


    return 0;
}
