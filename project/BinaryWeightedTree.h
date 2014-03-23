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


#define NUM_TOP_WORDS 3


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
    void printTopWords(std::string word);
    
protected:
    void printTreeInternal(BSTNode *node);
    void printTopWordsInternal(BSTNode *node, std::string word);
    
    
    class TopWords
    {
    public:
        TopWords(int n = NUM_TOP_WORDS)
        {
            *m_pNodes = new BSTNode[n];
        }
        ~TopWords()
        {
            delete [] m_pNodes;
        }
        void insert(BSTNode* node) {}
        
    private:
        BSTNode **m_pNodes;
    };
    
    
private:
    BSTNode *m_head;
};


#endif /* defined(__project__BinarySearchTree__) */
