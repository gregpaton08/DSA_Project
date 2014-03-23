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
    
    BSTNode *curr = m_head;
    
    while (nullptr != curr) {
        if (word.compare(curr->word) > 0) {
            curr = curr->rightChild;
        }
        else if (word.compare(curr->word) <= 0) {
            return curr;
        }
    }
    
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


void BinaryWeightedTree::printTopWords(std::string word)
{
    // Find subtree containing possible matches
    BSTNode *node = search(word);
    
    printTopWordsInternal(node, word);
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


void BinaryWeightedTree::printTopWordsInternal(BSTNode *node, std::string word)
{
    // Base case
    if (nullptr == node) {
        return;
    }
    
    // Traverse left subtree until a word is found that is
    // less than the input word
    if (nullptr != node->leftChild) {
        if (node->leftChild->word.compare(word) >= 0) {
            printTopWordsInternal(node->leftChild, word);
        }
    }
    
    // Print the node
    printf("%s\n", node->word.c_str());
    
    // Traverse right subtree
    if (nullptr != node->rightChild) {
        printTopWordsInternal(node->rightChild, word);
    }
}