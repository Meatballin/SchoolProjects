#include <iostream>
#include "BinSearchTree.hpp"
#include <queue>

TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( local_insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( local_insert( root->leftSubtree(), v ) );
    return root;
}

void BinSearchTree::insert(int v) {
    if( ! find(v) )
        root = local_insert( root, v );
}

bool BinSearchTree::find( int v )
{
    return findVal(root, v);
}

bool BinSearchTree::findVal(TreeNode *root, int v)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root->value() == v)
    {
        return true;
    }
    //call recursively if we don't find value
    if(v > root->value())
    {
        return findVal(root->rightSubtree(), v);
    }
    return findVal(root->leftSubtree(), v);


}

bool BinSearchTree::iterFind( int v )
{
    return iterFindVal(root, v);
}

bool BinSearchTree::iterFindVal(TreeNode *root, int v)
{
    TreeNode* tempNode;
    tempNode = root;
    while(tempNode != nullptr)
    {
        if(v == tempNode->value())
        {
            return true;
        }
        if(v < tempNode->value())
        {
            tempNode = tempNode->leftSubtree();
        }
        else
             tempNode = tempNode->rightSubtree();
    }
    //if root becomes null, we haven't found the value in the tree
    return false;
}

int  BinSearchTree::size()
{
    return treeSize(root);
}

int BinSearchTree::treeSize(TreeNode *root)
{
    if(root == nullptr)
    {
        return 0;
    }

    //Add our root node and recursively traverse adding 1 each time we do not run into a null node
    return 1 + treeSize(root->leftSubtree()) + treeSize(root->rightSubtree());
}

void BinSearchTree::inorderDump()
{
    inorderDumpHelper(root);
}

void BinSearchTree::inorderDumpHelper(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    inorderDumpHelper(root->leftSubtree());
    std::cout << root->value() << "\n";
    inorderDumpHelper(root->rightSubtree());
}

int BinSearchTree::maxDepth()
{
    return maxDepthhelper(root);
}

int BinSearchTree::maxDepthhelper(TreeNode *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return 1 + std::max(maxDepthhelper(root->leftSubtree()), maxDepthhelper(root->rightSubtree()));
}

void BinSearchTree::levelOrderDump()
{
    levelOrderDumpHelper(root);
}

void BinSearchTree::levelOrderDumpHelper(TreeNode *root)
{
    std::queue<TreeNode*> myQueue;
    //Create a temporary node to keep track of current node
    TreeNode *tempQueueNode;
    //stores whichever root node we are at into the queue
    if(root == nullptr)
    {
        return;
    }

    //push first node of tree into the queue
    myQueue.push(root);
    while(!myQueue.empty())
    {

        //set tempQueueNode to the root of the tree
        tempQueueNode = myQueue.front();

        //pop off queue to make room for children nodes of the root
        myQueue.pop();

        if(tempQueueNode->leftSubtree() != nullptr)
        {
            myQueue.push(tempQueueNode->leftSubtree());

        }
        if(tempQueueNode->rightSubtree() != nullptr)
        {
            myQueue.push(tempQueueNode->rightSubtree());
        }
        std::cout << tempQueueNode->value() << "\n";

    }
}

bool BinSearchTree::remove( int v )
{
    if(root == nullptr)
    {
        return false;
    }
    if(find(v))
    {
        return removeHelper(&root, v);
    }
    return true;
}

bool BinSearchTree::removeHelper(TreeNode **root, int v)
{
    TreeNode* tempTree = *root;
    TreeNode* previousNode = nullptr;
    TreeNode *tempStore;
    //first find the value in the tree
    while((tempTree != nullptr) && (tempTree->value() != v))
    {
        previousNode = tempTree;
        if(v < tempTree->value())
        {
            tempTree = tempTree->leftSubtree();
        }
        else
             tempTree = tempTree->rightSubtree();

    }

    //if tempTree is NULL here, we did not find the value
    if(tempTree == nullptr)
    {
        return false;
    }

    //This checks if we are at a leaf node
    if(!tempTree->leftSubtree() && !tempTree->rightSubtree())
    {
        //First need to check if our value is the root or else we dereference
        //a null ptr and crash.
        if(tempTree->value() == (*root)->value())
        {
            (*root) = nullptr;
            return true;
        }
        if(previousNode->leftSubtree() == tempTree)
        {
            previousNode->leftSubtree(nullptr);
            return true;
        }
        else
        {
            previousNode->rightSubtree(nullptr);
            return true;
        }


    }
    //Check if our node has at most one child
    //Also have to check if it is the root of the tree, since the root could also have one child
    if(((tempTree->leftSubtree() == nullptr) || (tempTree->rightSubtree() == nullptr)))
    {

        //First check if our searched value to remove is the root of the tree.
        if((*root)->value() == tempTree->value())
        {
            if(tempTree->leftSubtree() == nullptr)
            {
                (*root) = (*root)->rightSubtree();
                return true;
            }
            else
            {
                (*root) = (*root)->leftSubtree();
                return true;
            }
        }
        if(previousNode->leftSubtree() == tempTree)
        {
            if(tempTree->rightSubtree() != nullptr)
            {
                previousNode->leftSubtree(tempTree->rightSubtree());
                return true;
            }
            else
            {
                previousNode->leftSubtree(tempTree->leftSubtree());
                return true;
            }
        }
        else if(previousNode->rightSubtree() == tempTree)
        {
            if(tempTree->rightSubtree() != nullptr)
            {
                previousNode->rightSubtree(tempTree->rightSubtree());
                return true;
            }
            else
            {
                previousNode->rightSubtree(tempTree->leftSubtree());
                return true;
            }
        }


    }
    //Check if our node has two children
    if((tempTree->leftSubtree()) && tempTree->rightSubtree())
    {
        tempStore = tempTree;
        //find inorder successor
        if(tempTree->rightSubtree() != nullptr)
        {
            //going to find the minimum value of the right subtree
            previousNode = tempTree;
            tempTree = tempTree->rightSubtree();
            while(tempTree->leftSubtree() != nullptr)
            {
                previousNode = tempTree;
                tempTree = tempTree->leftSubtree();
            }
        }

        //inorder successor value swap
        tempStore->value() = tempTree->value();

        if(previousNode->rightSubtree() == tempTree)
        {
            if(tempTree->rightSubtree())
            {
                previousNode->rightSubtree(tempTree->rightSubtree());
                return true;
            }
            else
            {
                previousNode->rightSubtree(tempTree->leftSubtree());
                return true;
            }
        }
        else if(previousNode->leftSubtree() == tempTree)
        {
            if(tempTree->leftSubtree() == nullptr && tempTree->rightSubtree() == nullptr)
            {
                previousNode->leftSubtree(nullptr);
                return true;
            }
            else if(tempTree->rightSubtree())
            {
                previousNode->leftSubtree(tempTree->rightSubtree());
                return true;
            }
            return true;
        }

    }
    return true;
}

int BinSearchTree::kthSmallest(int k)
{
    TreeNode *temp;
    if(k > treeSize(root))
    {
        std::cout << "Your value is exceeding the size of the Binary Search Tree!\n";
        exit(EXIT_FAILURE);
    }
    temp = kthSmallesthelper(k, root);
    return temp->value();

}
TreeNode* BinSearchTree::kthSmallesthelper(int &k, TreeNode *root)
{
    TreeNode *temp;
    if(root == nullptr)
    {
        return nullptr;
    }
    temp = kthSmallesthelper(k, root->leftSubtree());
    if(temp != nullptr)
    {
        return temp;
    }
    k--;
    if(k == 0)
    {
        return root;
    }
    return kthSmallesthelper(k, root->rightSubtree());

}

void BinSearchTree::valuesAtLevel(int k)
{
    valuesAtLevelHelper(k, root);
}
void BinSearchTree::valuesAtLevelHelper(int k, TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    if(k == 1)
    {
        std::cout << root->value() << "\n";
        return;
    }
    valuesAtLevelHelper(k - 1, root->leftSubtree());
    valuesAtLevelHelper(k - 1, root->rightSubtree());
}

void BinSearchTree::iterValuesAtLevel(int k)
{
    iterValuesAtLevelHelper(k, root);
}
void BinSearchTree::iterValuesAtLevelHelper(int k, TreeNode *root)
{

    TreeNode *tempForRoot;
    int counter = k;
    //If no tree has been created, return to caller
    if(root == nullptr)
    {
        return;
    }
    //if k == 1 going into function, then the user wants the root printed
    if(k == 1)
    {
        std::cout << root->value() << "\n";
        return;
    }

    tempForRoot = root;
    std::queue<TreeNode*> myQueue;
    //Push root onto the queue
    myQueue.push(root);
    //Push a nullptr behind the root to signify that it's the end of the first level
    myQueue.push(nullptr);

    while(!myQueue.empty())
    {
        //If our counter is 1, then our queue contains the values we need for the kth level
        if(counter == 1)
        {
            break;
        }
        tempForRoot = myQueue.front();
        myQueue.pop();
        if(tempForRoot != nullptr)
        {
            if(tempForRoot->leftSubtree() != nullptr)
            {
                myQueue.push(tempForRoot->leftSubtree());
            }
            if(tempForRoot->rightSubtree() != nullptr)
            {
                myQueue.push(tempForRoot->rightSubtree());
            }
        }
        //If front of our queue is a nullptr, we go to this else. This means we are now
        //entering the next level of our BST, and need to push another nullptr to the
        //end of the queue, and decrement our counter
        else
        {
            myQueue.push(nullptr);
            counter--;
        }


    }
    //Prints what is left of the queue, which should be the level the user inputted
    while(!myQueue.empty())
    {
        //When we run into a nullptr, we need to break or else dereferencing it will crash function
        if(myQueue.front() == nullptr)
        {
            break;
        }
        std::cout << myQueue.front()->value() << "\n";
        myQueue.pop();
    }
    return;
}

int BinSearchTree::iterMaxDepth()
{
    return iterMaxDepthHelper(root);
}

int BinSearchTree::iterMaxDepthHelper(TreeNode *root)
{
    TreeNode *temp;
    int depth = 0;
    int count;

    if(root == nullptr)
    {
        return 0;
    }
    std::queue<TreeNode*> myQueue;
    myQueue.push(root);

    while(!myQueue.empty())
    {
        depth++;
        count = myQueue.size();
        //while our queue still has nodes in it
        while(count--)
        {
            temp = myQueue.front();
            if(temp->leftSubtree() != nullptr)
            {
                myQueue.push(temp->leftSubtree());
            }
            if(temp->rightSubtree() != nullptr)
            {
                myQueue.push(temp->rightSubtree());
            }
            myQueue.pop();
        }
    }
    return depth;

}

bool BinSearchTree::hasRootToLeafSum(int sum)
{
    return hasRootToLeafSumHelper(sum, root);
}

bool BinSearchTree::hasRootToLeafSumHelper(int sum, TreeNode *root)
{
    if(root == nullptr)
    {
        return false;
    }
    //If we get to a leaf node and our current sum is equal to the leaf's value
    //, then we have our root to leaf sum.
    if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr)
    {
        if(sum == root->value())
        {
            return true;
        }
        return false;
    }

    //Call left and right recursively, subtracting the sum from the current node value each time.
    //If we get to a leaf node and our current sum is the same as the leaf node's value
    //then we have found a RootToLeafSum
    return hasRootToLeafSumHelper(sum - root->value(), root->leftSubtree())
            || hasRootToLeafSumHelper(sum - root->value(), root->rightSubtree());

}

bool BinSearchTree::areIdentical(BinSearchTree *bst)
{
    return areIdenticalHelper(bst->root, root);
}

bool BinSearchTree::areIdenticalHelper(TreeNode *bst, TreeNode *root)
{
    //If either of our trees are empty, return true because we are constantly checking as we traverse further down
    // if our node values are not similar.
    if(bst == nullptr && root == nullptr)
    {
        return true;
    }
    if(bst != nullptr && root == nullptr)
    {
        return false;
    }
    if(bst == nullptr && root != nullptr)
    {
        return false;
    }
    //If we make it here, both current nodes are not null. So we can check if their values are equal.
    //In turn, this will also check for structural similarity
    if(bst && root)
    {
        return areIdenticalHelper(bst->leftSubtree(), root->leftSubtree())
        && areIdenticalHelper(bst->rightSubtree(), root->rightSubtree());
    }
    else
    {
        return false;
    }

}

BinSearchTree* BinSearchTree::intersectWith(BinSearchTree *bst)
{
    BinSearchTree *intersectTree = new BinSearchTree();
    intersectWithHelper(bst, root, &intersectTree);
    return intersectTree;
}

void BinSearchTree::intersectWithHelper(BinSearchTree *bst, TreeNode *root, BinSearchTree **intersectTree)
{
    //if our callee tree is empty, return a nullptr.
    if(root == nullptr)
    {
        return;
    }
    //If we find a value in our caller tree from our callee tree, insert it into our new tree.
    if(bst->find(root->value()))
    {
        (*intersectTree)->insert(root->value());
    }

    //Traverse left if we have a node on our left
    if(root->leftSubtree() != nullptr)
    {
        intersectWithHelper(bst, root->leftSubtree(), intersectTree);
    }
    //Traverse right otherwise
    if(root->rightSubtree() != nullptr)
    {
        intersectWithHelper(bst, root->rightSubtree(), intersectTree);
    }
    return;

}

BinSearchTree* BinSearchTree::unionWith(BinSearchTree *bst)
{
    BinSearchTree *unionTree = new BinSearchTree();
    unionWithDumpTreeHelper(bst->root, &unionTree);
    unionWithHelper(root, &unionTree);
    return unionTree;
}
void BinSearchTree::unionWithDumpTreeHelper(TreeNode *bst, BinSearchTree **unionTree)
{

    (*unionTree)->insert(bst->value());
    if(bst->leftSubtree() != nullptr)
    {
        unionWithDumpTreeHelper(bst->leftSubtree(), unionTree);
    }

    if(bst->rightSubtree() != nullptr)
    {
        unionWithDumpTreeHelper(bst->rightSubtree(), unionTree);
    }

}

void BinSearchTree::unionWithHelper(TreeNode *root, BinSearchTree **unionTree)
{

    if(!(*unionTree)->find(root->value()))
    {
        (*unionTree)->insert(root->value());
    }

    if(root->leftSubtree() != nullptr)
    {
        unionWithHelper(root->leftSubtree(), unionTree);
    }
    if(root->rightSubtree() != nullptr)
    {
        unionWithHelper(root->rightSubtree(), unionTree);
    }

}


//In differenceOF, put all elements of BST in a new differenceOf tree. Then traverse every element of our new tree
//and compare it with our callee tree. Use remove function on every element in differenceOf tree that occurs in the
//callee tree.
BinSearchTree* BinSearchTree::differenceOf(BinSearchTree *bst)
{
    BinSearchTree *differenceOfTree = new BinSearchTree();
    differenceOfDumpTreeHelper(bst->root, &differenceOfTree);
    differenceOfHelper(root, &differenceOfTree);
    return differenceOfTree;
}

void BinSearchTree::differenceOfHelper(TreeNode *root, BinSearchTree **differenceOftree)
{
    if((*differenceOftree)->find(root->value()))
    {
        (*differenceOftree)->remove(root->value());
    }
    if(root->leftSubtree() != nullptr)
    {
        differenceOfHelper(root->leftSubtree(), differenceOftree);
    }
    if(root->rightSubtree() != nullptr)
    {
        differenceOfHelper(root->rightSubtree(), differenceOftree);
    }
    return;

}

//dumps all of bst into our new tree that we will be returning to the caller
void BinSearchTree::differenceOfDumpTreeHelper(TreeNode *bst, BinSearchTree **differenceOfTree)
{
    (*differenceOfTree)->insert(bst->value());
    if(bst->leftSubtree() != nullptr)
    {
        differenceOfDumpTreeHelper(bst->leftSubtree(), differenceOfTree);
    }

    if(bst->rightSubtree() != nullptr)
    {
        differenceOfDumpTreeHelper(bst->rightSubtree(), differenceOfTree);
    }
}

