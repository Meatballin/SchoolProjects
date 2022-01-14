#include<stdlib.h>
#include "TreeNode.hpp"
#include <queue>

class BinSearchTree {
public:
    void insert(int v) ;
    bool find(int v);
    bool iterFind(int v);
    int  size();
    void inorderDump();
    int  maxDepth();
    void levelOrderDump();
    void levelOrderDumpHelper(TreeNode *root);
    bool remove(int v);
    int kthSmallest(int k) ;
    void valuesAtLevel(int k);
    void iterValuesAtLevel(int k);
    int iterMaxDepth();
    bool hasRootToLeafSum(int sum);
    bool areIdentical(BinSearchTree *bst);
    BinSearchTree *intersectWith(BinSearchTree *bst);
    BinSearchTree *unionWith(BinSearchTree *bst);
    BinSearchTree *differenceOf(BinSearchTree *bst);
    ~BinSearchTree();
private:
    bool iterFindVal(TreeNode *root, int v);
    bool findVal(TreeNode *root, int v);
    int treeSize(TreeNode *root);
    int maxDepthhelper(TreeNode *root);
    void inorderDumpHelper(TreeNode *root);
    bool removeHelper(TreeNode **root, int v);
    TreeNode *local_insert( TreeNode *, int );
    TreeNode* kthSmallesthelper(int &k, TreeNode *root);
    void valuesAtLevelHelper(int k, TreeNode *root);
    void iterValuesAtLevelHelper(int k, TreeNode *root);
    int iterMaxDepthHelper(TreeNode *root);
    bool hasRootToLeafSumHelper(int sum, TreeNode *root);
    bool areIdenticalHelper(TreeNode *bst, TreeNode *root);
    void intersectWithHelper(BinSearchTree *bst, TreeNode *root, BinSearchTree **intersectTree);
    void unionWithHelper(TreeNode *root, BinSearchTree **unionTree);
    void unionWithDumpTreeHelper(TreeNode *bst, BinSearchTree **unionTree);
    void differenceOfHelper(TreeNode *root, BinSearchTree **differenceOftree);
    void differenceOfDumpTreeHelper(TreeNode *bst, BinSearchTree **differenceOfTree);
    TreeNode *root;



};
