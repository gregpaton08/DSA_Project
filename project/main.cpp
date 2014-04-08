//
//  main.cpp
//  project
//
//  Created by Greg Paton on 3/22/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
#include "MemUsage.h"
#include "BinaryWeightedTree.h"


enum AC_Type {
    AC_BWT = 0,
    AC_TRIE
};

static int numSearches;


void printUsage(const char *argv0);
void runUserMode(AC_Type type);
void runTestMode(AC_Type type, const char *filepath, int n = INT_MAX, int len = 3);
void search(AutoComplete *pAc, int length, std::string word = "", int n = -1);


MemUsage mem;


int main(int argc, const char *argv[])
{
    if (2 == argc) {
        if (0 == strcmp("-bwt", argv[1])) {
            runUserMode(AC_BWT);
        }
        else if (0 == strcmp("-trie", argv[1])) {
            runUserMode(AC_TRIE);
        }
        else {
            printUsage(argv[0]);
            return -1;
        }
    }
    else if (3 == argc) {
        if (0 == strcmp("-bwt", argv[1])) {
            runTestMode(AC_BWT, argv[2]);
        }
        else if (0 == strcmp("-trie", argv[1])) {
            runTestMode(AC_TRIE, argv[2]);
        }
        else {
            printUsage(argv[0]);
            return -1;
        }
    }
    else if (4 == argc) {
        int n = atoi(argv[3]);
        if (0 == strcmp("-bwt", argv[1]) && n > 0) {
            runTestMode(AC_BWT, argv[2], n);
        }
        else if (0 == strcmp("-trie", argv[1]) && n > 0) {
            runTestMode(AC_TRIE, argv[2], n);
        }
        else {
            printUsage(argv[0]);
            return -1;
        }
        
    }
    else if (5 == argc) {
        int n   = atoi(argv[3]);
        int len = atoi(argv[4]);
        if (0 == strcmp("-bwt", argv[1]) && n > 0 && len >= 0) {
            runTestMode(AC_BWT, argv[2], n, len);
        }
        else if (0 == strcmp("-trie", argv[1]) && n > 0 && len >= 0) {
            runTestMode(AC_TRIE, argv[2], n, len);
        }
        else {
            printUsage(argv[0]);
            return -1;
        }
        
    }
    else {
        printUsage(argv[0]);
        return -1;
    }
    
    return 0;
}



void printUsage(const char *argv0)
{
    printf("User mode: %s -bwt\n", argv0);
    printf("           %s -trie\n", argv0);
    printf("Test mode: %s -bwt  <filepath>\n", argv0);
    printf("           %s -trie <filepath>\n", argv0);
    printf("           %s -bwt  <filepath> <num words>\n", argv0);
    printf("           %s -trie <filepath> <num words>\n", argv0);
    printf("           %s -bwt  <filepath> <num words> <max suffix length>\n", argv0);
    printf("           %s -trie <filepath> <num words> <max suffix length>\n", argv0);
}


void runUserMode(AC_Type type)
{
    AutoComplete *pAc;
    if (type == AC_BWT) {
        pAc = (AutoComplete*)new BWTAC;
    }
    else if (type == AC_TRIE) {
        pAc = (AutoComplete*)new Trie;
    }
    else {
        return;
    }
    
    printf("Populate dictionary:\n");
    
    while (true) {
        std::string input;
        std::cin >> input;
        
        if (std::string::npos != input.find("QUIT")) {
            break;
        }
        
        pAc->insert(input);
    }
    
    printf("Enter word to find matches for:\n");
    std::string input;
    std::cin >> input;
    pAc->printTopWords(input);
}


bool isNotAlpha(int c)
{
    return !std::isalpha(c);
}

void runTestMode(AC_Type type, const char *filepath, int n, int len)
{
    AutoComplete *pAc;
    if (type == AC_BWT) {
        pAc = (AutoComplete*)new BWTAC;
    }
    else if (type == AC_TRIE) {
        pAc = (AutoComplete*)new Trie;
    }
    else {
        return;
    }
    
    clock_t timer;
    uint64_t wordCount = 0;
    
    std::ifstream file;
    file.open(filepath);
    std::string word;
    int count = 0;
    
    timer = clock();
    
    // Read all words from a file
    while (file >> word && count++ < n) {
        // Remove non-letter characters
        word.erase(std::remove_if(word.begin(), word.end(), isNotAlpha), word.end());
        pAc->insert(word);
        ++wordCount;
    }
    
    timer = clock() - timer;
    
    printf("Total words:    %llu\n", wordCount);
    printf("Insertion time: %.3fms\n", (float)(timer * 1000) / CLOCKS_PER_SEC);
    
    printf("Mem usage:      %lu\n", mem.Usage());
    
    if (len == 0) {
        return;
    }
    
    numSearches = 0;
    timer = clock();
    
    search(pAc, len);
    
    timer = clock() - timer;
    
    printf("Retrieval time: %.3fms\n", (float)(timer * 1000) / CLOCKS_PER_SEC);
    printf("Num searches:   %d\n", numSearches);
}


void search(AutoComplete *pAc, int length, std::string word, int n) {
    // First call
    if (n == -1) {
        n = length;
    }
    // Base case
    else if (n == 0) {
        return;
    }
    
    std::string tempWord = word.c_str();
    for (char a = 'a'; a <= 'z'; ++a) {
        tempWord += a;
        //printf("%s\n", tempWord.c_str());
        if (n == 1) {
            pAc->findTopWords(tempWord);
            ++numSearches;
        }
        search(pAc, length, tempWord, n - 1);
        tempWord = word;
    }
}