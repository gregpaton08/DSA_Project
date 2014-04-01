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
#if 1
    int index = (int)word[0] - 97;
    if (nullptr == m_pChildren[index]) {
        m_pChildren[index] = new Trie;
    }
    
    // Call recursive internal method
    insertInternal(word, m_pChildren[index]);
#else
    insertInternal(word, this);
#endif
}


void Trie::insertInternal(std::string word, Trie *node)
{
    // Base case: empty string
    if (0 == word.compare("")) {
        return;
    }
    
    //node->addSuffix(word);
    node->addSuffix(word.substr(1));
    
    int index = (int)word[0] - 97;
    if (nullptr == node->m_pChildren[index]) {
        node->m_pChildren[index] = new Trie;
    }
    
    insertInternal(word.substr(1), node->m_pChildren[index]);
}


void Trie::printTrie()
{
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        if (nullptr != m_pChildren[i]) {
            WordNode *suffix = m_pChildren[i]->m_pSuffixes;
            do {
                printf("%c", (char)(i + 97));
                if (nullptr != suffix) {
                    printf("%s", suffix->word.c_str());
                }
                printf("\n");
            } while (nullptr != (suffix = suffix->next));
        }
    }
}


void Trie::addSuffix(std::string suffix)
{
    if (0 == suffix.compare("")) {
        return;
    }
    
    if (nullptr == m_pSuffixes) {
        m_pSuffixes = new WordNode;
        m_pSuffixes->word = suffix;
        m_pSuffixes->next = nullptr;
    }
    else {
        WordNode **curr = &m_pSuffixes;
        while (nullptr != (*curr)) {
//            if (suffix.compare((*curr)->word) >= 0) {
//                
//            }
            (curr = &((*curr)->next));
        }
        
        (*curr) = new WordNode;
        (*curr)->word = suffix;
        (*curr)->next = nullptr;
    }
}