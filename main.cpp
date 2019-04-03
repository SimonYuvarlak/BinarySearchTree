//
//  main.cpp
//  BinarySearchTree*
//
//  Created by Arda Yuvarlak on 19.03.2019.
//  Copyright © 2019 CHAIN. All rights reserved.
//


#include "PbBST.hpp"
#include <iostream>
using namespace std;

int main()
{
    BinarySearchTree* pointerBasedTree = new BinarySearchTree();
    int array[] = {40, 50, 45, 30, 60, 55, 20, 35, 10, 25, 17, 65, 56, 98, 76, 3, 14, 43, 9, 48, 31};
    BinarySearchTree* pointerBasedTree2 = new BinarySearchTree();
    int array2[] = {1};
    BinarySearchTree* pointerBasedTree3 = new BinarySearchTree();
    int array3[] = {};
    BinarySearchTree* pointerBasedTree4 = new BinarySearchTree();
    int array4[] = {1,1};
    BinarySearchTree* pointerBasedTree5 = new BinarySearchTree();
    int array5[] = {1,2};
    
    
    for(int i = 0; i < 21; i++)
        pointerBasedTree->insertKey(array[i]);
    
    for(int i = 0; i < 1; i++)
        pointerBasedTree2->insertKey(array2[i]);
    
    for(int i = 0; i < 0; i++)
        pointerBasedTree3->insertKey(array3[i]);
    
    for(int i = 0; i < 2; i++)
        pointerBasedTree4->insertKey(array4[i]);
    
    for(int i = 0; i < 2; i++)
        pointerBasedTree5->insertKey(array5[i]);
    
    //pointerBasedTree->inorderTraverse(pointerBasedTree->inorder(<#TreeNode *treePtr#>, <#FunctionType visit#>, <#int *array#>))
    
    cout<<pointerBasedTree->getHeight() << endl;
    cout<<pointerBasedTree2->getHeight() << endl;
    cout<<pointerBasedTree3->getHeight() << endl;
    cout<<pointerBasedTree4->getHeight() << endl;
    cout<<pointerBasedTree5->getHeight() << endl;
    
    return 0;
}




