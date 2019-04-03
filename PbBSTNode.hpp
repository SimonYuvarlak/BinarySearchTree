
//
//  main.cpp
//  BinarySearchTree*
//
//  Created by Arda Yuvarlak on 19.03.2019.
//  Copyright © 2019 CHAIN. All rights reserved.
//

#ifndef PbBSTNode_h
#define PbBSTNode_h

#include <stdio.h>
class TreeNode {
    
private:
    TreeNode();
    TreeNode(int &nodeItem, TreeNode *left, TreeNode *right);
    
    int item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
    
    
    
    friend class BinarySearchTree;
};
#endif /* PbBSTNode_hpp */

