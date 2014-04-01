//
//  Trie.h
//  project
//
//  Created by Greg Paton on 3/31/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#ifndef __project__Trie__
#define __project__Trie__

#include <iostream>

#define NUM_CHILDREN 26


class Trie
{
public:
    Trie();
    void insert(std::string word);
    void printTrie();
    
    struct WordNode
    {
        std::string word;
        WordNode *next;
    };
    
protected:
    void insertInternal(std::string word, Trie *node);
    void addSuffix(std::string suffix);
    
private:
    Trie *m_pChildren[NUM_CHILDREN];
    WordNode *m_pSuffixes;
};


#endif /* defined(__project__Trie__) */
