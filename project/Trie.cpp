//
//  Trie.cpp
//  project
//
//  Created by Greg Paton on 3/31/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include "Trie.h"
#include <algorithm>


bool suffixCompWeightFunc(Trie::WordNode a, Trie::WordNode b)
{
    return a.weight > b.weight;
}

bool suffixCompWordFun(Trie::WordNode a, Trie::WordNode b)
{
    return a.word.compare(b.word) < 0;
}


Trie::Trie()
{
    for (int i = 0; i < NUM_CHILDREN; ++i) {
        m_pChildren[i] = nullptr;
    }
}


bool Trie::insert(std::string word)
{
    // make string lower case for easier compare
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    int index = (int)word[0] - 97;
    if (nullptr == m_pChildren[index]) {
        m_pChildren[index] = new Trie;
    }
    
    // Call recursive internal method
    insertInternal(word, m_pChildren[index]);
    
    return true;
}


void Trie::insertInternal(std::string word, Trie *node)
{
    // Base case: empty string
    if (0 == word.compare("")) {
        return;
    }
    
    // Returns 1 if word is already in list
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


bool Trie::printTopWords(std::string word)
{
    printTopWordsInternal(word, "");
    
    return true;
}


void Trie::printTopWordsInternal(std::string word, std::string prefix)
{
    // Base case
    if (word.length() == 0/*1*/) {
        // print top 3 words
        std::list<WordNode>::iterator iter = m_pSuffixes.begin();
        for (int i = 0; i < 3 && i < m_pSuffixes.size(); ++i) {
            printf("%s%s\n", prefix.c_str(), iter->word.c_str());
            ++iter;
        }
        return;
    }
    
    if (m_pChildren[word[0] - 97]) {
        m_pChildren[word[0] - 97]->printTopWordsInternal(word.substr(1), prefix + word[0]);
    }
    
    return;
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
        std::list<WordNode>::iterator locIter = m_pSuffixes.end();
        for (std::list<WordNode>::iterator iter = m_pSuffixes.begin(); iter != m_pSuffixes.end(); ++iter) {
            int compRet = suffix.compare(iter->word);
            // If word is in the list then increment the weight and sort
            if (compRet == 0) {
                ++iter->weight;
                m_pSuffixes.sort(suffixCompWordFun);
                m_pSuffixes.sort(suffixCompWeightFunc);
                return 0;
            }
            // Store where word should be inserted if the word is not in the list
            else if (compRet < 0 && iter->weight == 0) {
                if (locIter == m_pSuffixes.end()) {
                    locIter = iter;
                }
            }
        }
        WordNode node;
        node.word = suffix;
        m_pSuffixes.insert(locIter, node);
    }
    
    return 0;
}


bool Trie::findTopWords(std::string word)
{
    findTopWordsInternal(word, "");
    
    return true;
}


void Trie::findTopWordsInternal(std::string word, std::string prefix)
{
    // Base case
    if (word.length() == 0) {
        // print top 3 words
        std::list<WordNode>::iterator iter = m_pSuffixes.begin();
        for (int i = 0; i < 3 && i < m_pSuffixes.size(); ++i) {
            //printf("%s%s\n", prefix.c_str(), iter->word.c_str());
            ++iter;
        }
        return;
    }
    
    if (m_pChildren[word[0] - 97]) {
        m_pChildren[word[0] - 97]->findTopWordsInternal(word.substr(1), prefix + word[0]);
    }
    
    return;
}

