//
//  BinarySearchTree.h
//  project
//
//  Created by Greg Paton on 3/22/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#ifndef __project__BinarySearchTree__
#define __project__BinarySearchTree__

#include <iostream>


struct BSTNode {
    std::string word;
    int         weight;
    BSTNode     *leftChild;
    BSTNode     *rightChild;
};


class BinaryWeightedTree
{
public:
    BinaryWeightedTree();
    BSTNode* search(std::string word);
    void insert(std::string str);
    void printTree();
    void printTopThree();
    
protected:
    void printTreeInternal(BSTNode *node);
    
private:
    BSTNode *m_head;
};


#endif /* defined(__project__BinarySearchTree__) */
