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


class AutoComplete
{
public:
    AutoComplete() {}
    virtual bool insert(std::string word) = 0;
    virtual bool findTopWords(std::string word) = 0;
    virtual bool printTopWords(std::string word) = 0;
    
    static int getIndexFromWord(std::string word)
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
};


#endif /* defined(__project__AutoComplete__) */
