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
#include <list>
#include "AutoComplete.h"

#define NUM_CHILDREN 26


class Trie : AutoComplete
{
public:
    Trie();
    virtual bool insert(std::string word);
    virtual bool printTopWords(std::string word) { return false; }
    void printTrie();
    virtual bool findTopWords(std::string word);
    
    class WordNode
    {
    public:
        WordNode()
        {
            word = "";
            weight = 0;
        }
        
    public:
        std::string word;
        int weight;
        //WordNode *next;
    };
    
protected:
    void insertInternal(std::string word, Trie *node);
    int addSuffix(std::string suffix);
    void findTopWordsInternal(std::string word, std::string prefix);
    
private:
    Trie *m_pChildren[NUM_CHILDREN];
    std::list<WordNode> m_pSuffixes;
};


#endif /* defined(__project__Trie__) */
