//
//  main.cpp
//  BinarySearchTree*
//
//  Created by Arda Yuvarlak on 19.03.2019.
//  Copyright © 2019 CHAIN. All rights reserved.
//


#ifndef PbBST_h
#define PbBST_h

#include <stdio.h>
#include "PbBSTNode.hpp"

typedef void (*FunctionType)(int& anItem);

class BinarySearchTree{
public:
    BinarySearchTree();
    BinarySearchTree(BinarySearchTree &tree);
    ~BinarySearchTree();
    
    
    void insertKey(int key);
    void deleteKey(int key);
    int getHeight();
    int getNodeCount();
    int getNodesRequired();
    int getFullBTLevel();
    
private:
    TreeNode *root;
    void addNode(TreeNode* treePtr,int item);
    void deleteKey(TreeNode* &current,int key);
    int deleteLeaf(TreeNode* &treePtr);
    void removeTree(TreeNode* treePtr);
    int findHeight(TreeNode* treePtr);
    int findNodeCount(TreeNode* treePtr);
    int findNodesRequired(TreeNode* treePtr);
    int findFullBTLevel(TreeNode* treePtr);
    void preorderTraverse(FunctionType visit);
    void inorderTraverse(FunctionType visit);
    void postorderTraverse(FunctionType visit);
    void preorder(TreeNode *treePtr, FunctionType visit);
    void postorder(TreeNode *treePtr, FunctionType visit);
    void inorder(TreeNode *treePtr, FunctionType visit, int *array);

    
};

#endif /* PbBST_h */

