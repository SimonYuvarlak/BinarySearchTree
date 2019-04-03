//
//  main.cpp
//  BinarySearchTree*
//
//  Created by Arda Yuvarlak on 19.03.2019.
//  Copyright © 2019 CHAIN. All rights reserved.
//

#include "PbBST.hpp"
#include "string"
using namespace std;


BinarySearchTree::BinarySearchTree(){
    this->root = NULL;
}
BinarySearchTree::BinarySearchTree(BinarySearchTree &tree){
    this->root = new TreeNode();
    root -> item = tree.root -> item;
    root -> leftChildPtr = tree.root -> leftChildPtr;
    root -> rightChildPtr = tree.root -> rightChildPtr;
}

BinarySearchTree::~BinarySearchTree()
{
    removeTree(root);
}

void BinarySearchTree::removeTree(TreeNode* node)
{
    if(node == NULL)
        return;
    removeTree(node->leftChildPtr);
    removeTree(node->rightChildPtr);
    delete node;
}


void BinarySearchTree::insertKey(int key){
    if(this->root == NULL){
        this->root = new TreeNode();
        this->root-> item = key;
        this->root->leftChildPtr = NULL;
        this->root->rightChildPtr = NULL;
        return;
    }
    addNode(root,key);
}

void BinarySearchTree::addNode(TreeNode* node,int value)
{
    if(value < node->item)
    {
        if(node->leftChildPtr == NULL){
            node->leftChildPtr = new TreeNode();
            node->leftChildPtr->item = value;
            node->leftChildPtr->leftChildPtr = NULL;
            node->leftChildPtr->rightChildPtr = NULL;
            return;
        }
        addNode(node->leftChildPtr,value);
    }
    else
    {
        if(node->rightChildPtr == NULL){
            node->rightChildPtr = new TreeNode();
            node->rightChildPtr->item = value;
            node->rightChildPtr->leftChildPtr = NULL;
            node->rightChildPtr->rightChildPtr = NULL;
            return;
        }
        addNode(node->rightChildPtr,value);
    }
}

void BinarySearchTree::deleteKey(int key){
    deleteKey(root,key);
}

void BinarySearchTree::deleteKey(TreeNode* &current,int key){
    if(current != NULL){
        if(current->item == key){
            if(current->leftChildPtr == NULL)
                current = current->rightChildPtr;
            else if(current->rightChildPtr == NULL)
                current = current->leftChildPtr;
            else{
                int leafvalue = deleteLeaf(current->rightChildPtr);
                current->item = leafvalue;
            }
        }else if(current->item < key)
            deleteKey(current->rightChildPtr,key);
        else
            deleteKey(current->leftChildPtr,key);
    }
}
int BinarySearchTree::deleteLeaf(TreeNode* &node){
    if(node->leftChildPtr == NULL){
        int value = node->item;
        node = node->rightChildPtr;
        return value;
    }else
        return deleteLeaf(node->leftChildPtr);
}

int BinarySearchTree::getHeight()
{
    return findHeight(root);
}

int BinarySearchTree::findHeight(TreeNode* node)
{
    int leftHeight = 1;
    int rightHeight = 1;
    if(node == NULL)
        return 0;
    for(;node->leftChildPtr != NULL; node->leftChildPtr = node->leftChildPtr->leftChildPtr ){
        leftHeight = leftHeight + 1;
    }
    for(;node->rightChildPtr != NULL; node->rightChildPtr = node->rightChildPtr->rightChildPtr ){
        rightHeight = rightHeight + 1;
    }
    if(leftHeight > rightHeight)
        return leftHeight;
    return rightHeight;
}

int BinarySearchTree::getNodeCount(){
    return findNodeCount(root);
}

int BinarySearchTree::findNodeCount(TreeNode* node){
    if(node == NULL)
        return 0;
    
    int leftSize = findNodeCount(node->leftChildPtr);
    int rightSize = findNodeCount(node->rightChildPtr);
    return leftSize + rightSize + 1;
}
int BinarySearchTree::getNodesRequired()
{
    return findNodesRequired(root);
}
int BinarySearchTree::findNodesRequired(TreeNode* node){
    int a = findNodeCount(node);
    int c = 1;
    for (int b=getHeight(); b>0 ; b-- ){
        c= c*2;
    }
    c=c-1;
    a= a-c;
    return a;
}
int BinarySearchTree::getFullBTLevel(){
    return findFullBTLevel(root);
}
int BinarySearchTree::findFullBTLevel(TreeNode* node){ // @suppress("No return")
    if(node == NULL)
        return 0;
    int fullLevel = 0;
    if (node->leftChildPtr != NULL && node->rightChildPtr != NULL){
        fullLevel = fullLevel+1;
        
    }
    return fullLevel;
}

void BinarySearchTree::preorderTraverse(FunctionType visit){
    preorder(root, visit);
}

void BinarySearchTree::postorderTraverse(FunctionType visit){
    postorder(root, visit);
}

void BinarySearchTree::inorderTraverse(FunctionType visit){
    inorder(root, visit);
}

void BinarySearchTree::preorder(TreeNode *treePtr, FunctionType visit) {
    if (treePtr != NULL) {
        visit(treePtr->item);
        preorder(treePtr->leftChildPtr, visit);
        preorder(treePtr->rightChildPtr, visit);
    }
}

void BinarySearchTree::inorder(TreeNode *treePtr, FunctionType visit) {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr, visit);
        visit(treePtr->item);
        inorder(treePtr->rightChildPtr, visit);
    }
}

void BinarySearchTree::postorder(TreeNode *treePtr, FunctionType visit) {
    if (treePtr != NULL) {
        postorder(treePtr->leftChildPtr, visit);
        postorder(treePtr->rightChildPtr, visit);
        visit(treePtr->item);
    }
}



