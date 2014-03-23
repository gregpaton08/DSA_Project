//
//  main.cpp
//  project
//
//  Created by Greg Paton on 3/22/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include <iostream>
#include "BinaryWeightedTree.h"

int main(int argc, const char * argv[])
{
    BinaryWeightedTree bwt;
    
    printf("Populate dictionary:\n\n");
    
    while (true) {
        std::string input;
        std::cin >> input;
        
        if (std::string::npos != input.find("QUIT")) {
            break;
        }
        
        bwt.insert(input);
    }
    
#if 0
    printf("Printing tree...\n");
    bwt.printTree();
#else
    printf("Enter word to find matches for:\n");
    std::string input;
    std::cin >> input;
    bwt.printTopWords(input);
#endif
    
    return 0;
}

