//
//  TopWords.h
//  project
//
//  Created by Greg Paton on 3/23/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#ifndef __project__TopWords__
#define __project__TopWords__

#include <iostream>
#include "Types.h"


class TopWords
{
public:
    TopWords();
    ~TopWords();
    void insert(BSTNode *bstnode);
    
protected:
    void removeLastNode();
    
private:
    TopWordNode *m_pHead;
    int m_numWords;
};

#endif /* defined(__project__TopWords__) */
