//
//  main.cpp
//  BinarySearchTree*
//
//  Created by Arda Yuvarlak on 19.03.2019.
//  Copyright © 2019 CHAIN. All rights reserved.
//

#include "PbBSTNode.hpp"

TreeNode::TreeNode(){}

TreeNode::TreeNode(int &nodeItem, TreeNode *left = NULL, TreeNode *right = NULL): item(nodeItem), leftChildPtr(left), rightChildPtr(right){}


