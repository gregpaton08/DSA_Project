//
//  Trie.cpp
//  project
//
//  Created by Greg Paton on 3/31/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include "Trie.h"


Trie::Trie()
{
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        m_pChildren[i] = nullptr;
    }
    
    m_pSuffixes = nullptr;
}


void Trie::insert(std::string word)
{
    // make string lower case for easier compare
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    // Call recursive internal method
    insertInternal(word, this);
}


void Trie::insertInternal(std::string word, Trie *node)
{
    // Base case: empty string
    if (word.compare("")) {
        return;
    }
    
    addSuffix(word.substr(1));
}


void Trie::addSuffix(std::string suffix)
{
    if (suffix.compare("")) {
        return;
    }
    
    if (nullptr == m_pSuffixes) {
        m_pSuffixes = new WordNode;
        m_pSuffixes->word = suffix;
        m_pSuffixes->next = nullptr;
    }
    else {
        WordNode *curr = m_pSuffixes;
        WordNode *prev;
        while (nullptr != (curr = curr->next)) {
            prev = curr;
        }
        
        prev = new WordNode;
        prev->word = suffix;
        prev->next = nullptr;
    }
}