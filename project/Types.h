//
//  Types.h
//  project
//
//  Created by Greg Paton on 3/23/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#ifndef project_Types_h
#define project_Types_h


struct BWTNode {
    std::string word;
    int         weight;
    BWTNode     *leftChild;
    BWTNode     *rightChild;
};


struct TopWordNode {
    BWTNode *node;
    TopWordNode *next;
};


#endif
