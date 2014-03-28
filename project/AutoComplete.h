//
//  AutoComplete.h
//  project
//
//  Created by Greg Paton on 3/27/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#ifndef __project__AutoComplete__
#define __project__AutoComplete__

#include <iostream>
#include "BinaryWeightedTree.h"


class AutoComplete
{
public:
    AutoComplete();
    bool insert(std::string word);
    bool printTopWords(std::string word);
    
protected:
    int getIndexFromWord(std::string word);
    
private:
    BinaryWeightedTree m_bwt[26];   // One binary weighted tree for each letter
};


#endif /* defined(__project__AutoComplete__) */
