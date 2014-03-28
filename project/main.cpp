//
//  main.cpp
//  project
//
//  Created by Greg Paton on 3/22/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include <iostream>
#include "AutoComplete.h"

int main(int argc, const char * argv[])
{
    AutoComplete ac;
    
    printf("Populate dictionary:\n");
    
    while (true) {
        std::string input;
        std::cin >> input;
        
        if (std::string::npos != input.find("QUIT")) {
            break;
        }
        
        ac.insert(input);
    }
    
    printf("Enter word to find matches for:\n");
    std::string input;
    std::cin >> input;
    ac.printTopWords(input);
    
    return 0;
}

