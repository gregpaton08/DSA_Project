//
//  BinarySearchTree.cpp
//  project
//
//  Created by Greg Paton on 3/22/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include "BinaryWeightedTree.h"


BinaryWeightedTree::BinaryWeightedTree()
{
    m_head = nullptr;
}


BSTNode* BinaryWeightedTree::search(std::string word)
{
    // make string lower case for easier compare
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    return nullptr;
}


void BinaryWeightedTree::insert(std::string str)
{
    // make string lower case for easier compare
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    BSTNode **curr = &m_head;
    
    while (nullptr != *curr) {
        if ((*curr)->word.compare(str) < 0) {
            curr = &((*curr)->rightChild);
        }
        else if (m_head->word.compare(str) > 0) {
            curr = &((*curr)->leftChild);
        }
        else {
            ++(*curr)->weight;
            return;
        }
    }
    
    *curr = new BSTNode;
    (*curr)->word = str;
    (*curr)->weight = 0;
    (*curr)->leftChild = nullptr;
    (*curr)->rightChild = nullptr;
}


void BinaryWeightedTree::printTree()
{
    printTreeInternal(m_head);
}


void BinaryWeightedTree::printTopThree()
{
    
}


void BinaryWeightedTree::printTreeInternal(BSTNode *node)
{
    // Print tree in depth first order
    
    // Base case
    if (nullptr == node) {
        return;
    }
    
    // Print left subtree
    if (nullptr != node->leftChild) {
        printTreeInternal(node->leftChild);
    }
    
    // Print head
    printf("%s\n", node->word.c_str());
    
    // Print right subtree
    if (nullptr != node->rightChild) {
        printTreeInternal(node->rightChild);
    }
}