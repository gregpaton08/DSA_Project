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
    BinarySearchTree bst;
    
    while (true) {
        std::string input;
        std::cin >> input;
        
        if (std::string::npos != input.find("QUIT")) {
            break;
        }
        
        bst.insert(input);
    }
    
    printf("Printing tree...\n");
    bst.printTree();
    
    return 0;
}

