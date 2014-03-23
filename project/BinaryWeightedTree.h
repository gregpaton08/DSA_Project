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
#include "Types.h"
#include "TopWords.h"


#define NUM_TOP_WORDS 3


class BinaryWeightedTree
{
public:
    BinaryWeightedTree();
    BSTNode* search(std::string word);
    void insert(std::string str);
    void printTree();
    void printTopWords(std::string word);
    
protected:
    void printTreeInternal(BSTNode *node);
    void printTopWordsInternal(BSTNode *node, std::string word);
    
    
    
    
    
private:
    BSTNode *m_head;
    TopWords m_topWords;
};


#endif /* defined(__project__BinarySearchTree__) */
