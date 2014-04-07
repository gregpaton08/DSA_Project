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
#include "AutoComplete.h"


#define NUM_TOP_WORDS 3


class BinaryWeightedTree
{
public:
    BinaryWeightedTree();
    BWTNode* search(std::string word);
    void insert(std::string str);
    void printTree();
    void printTopWords(std::string word);
    void findTopWords(std::string word);
    
protected:
    void printTreeInternal(BWTNode *node);
    void printTopWordsInternal(BWTNode *node, std::string word);
    void findTopWordsInternal(BWTNode *node, std::string word);
    
private:
    BWTNode *m_head;
    TopWords m_topWords;
};


class BWTAC : AutoComplete
{
public:
    BWTAC() { }
    virtual bool insert(std::string word)
    {
        int idx = getIndexFromWord(word);
        if (idx < 0) {
            return false;
        }
        
        m_bwt[idx].insert(word);
        
        return true;
    }
    virtual bool printTopWords(std::string word)
    {
        int idx = getIndexFromWord(word);
        if (idx < 0) {
            return false;
        }
        
        m_bwt[idx].printTopWords(word);
        
        return true;
    }
    virtual bool findTopWords(std::string word)
    {
        int idx = getIndexFromWord(word);
        if (idx < 0) {
            return false;
        }
        
        m_bwt[idx].findTopWords(word);
        
        return true;
    }
    
private:
    BinaryWeightedTree m_bwt[26];   // One binary weighted tree for each letter
};


#endif /* defined(__project__BinarySearchTree__) */
