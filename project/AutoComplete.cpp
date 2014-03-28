//
//  AutoComplete.cpp
//  project
//
//  Created by Greg Paton on 3/27/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include "AutoComplete.h"


AutoComplete::AutoComplete()
{
    
}


bool AutoComplete::insert(std::string word)
{
    int idx = getIndexFromWord(word);
    if (idx < 0) {
        return false;
    }
    
    m_bwt[idx].insert(word);
    
    return true;
}


bool AutoComplete::printTopWords(std::string word)
{
    int idx = getIndexFromWord(word);
    if (idx < 0) {
        return false;
    }
    
    m_bwt[idx].printTopWords(word);
    
    return true;
}


bool AutoComplete::findTopWords(std::string word)
{
    int idx = getIndexFromWord(word);
    if (idx < 0) {
        return false;
    }
    
    m_bwt[idx].findTopWords(word);
    
    return true;
}


int AutoComplete::getIndexFromWord(std::string word)
{
    if (0 == word.length()) {
        return -1;
    }
    
    char c = word[0];
    int idx = (int)c - 97;
    if ((int)c < 97) {
        idx = (int)c - 65;
    }
    
    if (idx < 0 || idx > 25) {
        return -1;
    }
    
    return idx;
}