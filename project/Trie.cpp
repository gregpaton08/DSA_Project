//
//  Trie.cpp
//  project
//
//  Created by Greg Paton on 3/31/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include "Trie.h"


bool suffixCompFunc(Trie::WordNode a, Trie::WordNode b)
{
    return a.weight > b.weight;
}


Trie::Trie()
{
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        m_pChildren[i] = nullptr;
    }
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
    if (1 == node->addSuffix(word.substr(1))) {
        return;
    }
    
    if (1 == word.length()) {
        return;
    }
    
    int index = (int)word[1] - 97;
    if (nullptr == node->m_pChildren[index]) {
        node->m_pChildren[index] = new Trie;
    }
    
    insertInternal(word.substr(1), node->m_pChildren[index]);
}


void Trie::printTrie()
{
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        if (nullptr != m_pChildren[i]) {
            for (std::list<WordNode>::iterator iter = m_pSuffixes.begin(); iter != m_pSuffixes.end(); ++iter) {
                printf("%c", (char)(i + 97));
                printf("%s", iter->word.c_str());
                printf("\n");
            }
        }
    }
}


int Trie::addSuffix(std::string suffix)
{
    if (0 == suffix.compare("")) {
        return 0;
    }
    
    // Start list
    if (m_pSuffixes.size() == 0) {
        WordNode node;
        node.word = suffix;
        m_pSuffixes.push_back(node);
    }
    // Add to list
    else {
        for (std::list<WordNode>::iterator iter = m_pSuffixes.begin(); iter != m_pSuffixes.end(); ++iter) {
            int compRet = suffix.compare(iter->word);
            if (compRet == 0) {
                ++iter->weight;
                m_pSuffixes.sort(suffixCompFunc);
                break;
            }
            else if (compRet < 0) {
                WordNode node;
                node.word = suffix;
                m_pSuffixes.insert(iter, node);
                break;
            }
        }
    }
    
    return 0;
}


void Trie::findTopWords(std::string word)
{
    
}