//
//  main.cpp
//  project
//
//  Created by Greg Paton on 3/22/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "AutoComplete.h"
#include "Trie.h"
#include "MemUsage.h"


void printUsage(const char *argv0);
void runUserMode();
void runTestMode(const char *filepath);
void runUserModeTrie();
void runTestModeTrie(const char *filepath);


int main(int argc, const char *argv[])
{
    if (2 == argc) {
        if (0 == strcmp("-trie", argv[1])) {
            runUserModeTrie();
        }
        else if (0 == strcmp("-bwt", argv[1])) {
            runUserMode();
        }
    }
    else if (3 == argc) {
        if (0 == strcmp("-bwt", argv[1])) {
            runTestMode(argv[2]);
        }
        else if (0 == strcmp("-trie", argv[1])) {
            runTestModeTrie(argv[2]);
        }
        else {
            printUsage(argv[0]);
            return -1;
        }
    }
    else if (argc > 3) {
        printUsage(argv[0]);
        return -1;
    }
    
    return 0;
}



void printUsage(const char *argv0)
{
    printf("Usage:     %s\n", argv0);
    printf("Test mode: %s -t <filepath>\n", argv0);
}


void runUserMode()
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
}


bool isNotAlpha(int c)
{
    return !std::isalpha(c);
}

void runTestMode(const char *filepath)
{
    AutoComplete ac;
    clock_t timer;
    uint64_t wordCount = 0;
    
    std::ifstream file;
    file.open(filepath);
    std::string word;
    timer = clock();
    
    while (file >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), isNotAlpha), word.end());
        ac.insert(word);
        ++wordCount;
    }
    timer = clock() - timer;
    
    printf("Total words:    %llu\n", wordCount);
    printf("Insertion time: %.3fms\n", (float)(timer * 1000) / CLOCKS_PER_SEC);
    
    std::string input;
    timer = clock();
    for (char a = 'a'; a <= 'z'; ++a) {
        input = a;
        ac.findTopWords(input);
        for (char b = 'a'; b <= 'z'; ++b) {
            input = input.substr(0, 1) + b;
            ac.findTopWords(input);
            for (char c = 'a'; c <= 'z'; ++c) {
                ac.findTopWords(input);
                input = input.substr(0, 2) + c;
            }
            input = input.substr(0, 1);
        }
        input = "";
    }
    timer = clock() - timer;
    
    printf("Retrieval time: %.3fms\n", (float)(timer * 1000) / CLOCKS_PER_SEC);
}


void runUserModeTrie()
{
    Trie trie;
    
    printf("Populate dictionary:\n");
    
    while (true) {
        std::string input;
        std::cin >> input;
        
        if (std::string::npos != input.find("QUIT")) {
            break;
        }
        
        trie.insert(input);
    }
    
    trie.printTrie();
}


void runTestModeTrie(const char *filepath)
{
    Trie trie;
    clock_t timer;
    uint64_t wordCount = 0;
    
    std::ifstream file;
    file.open(filepath);
    std::string word;
    timer = clock();
    
    while (file >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), isNotAlpha), word.end());
        trie.insert(word);
        ++wordCount;
    }
    
    timer = clock() - timer;
    
    printf("Total words:    %llu\n", wordCount);
    printf("Insertion time: %.3fms\n", (float)(timer * 1000) / CLOCKS_PER_SEC);
    
    MemUsage mem;
    printf("Memory: %lu\n", mem.Usage() / 1024);
    
    std::string input;
    timer = clock();
    for (char a = 'a'; a <= 'z'; ++a) {
        input = a;
        trie.findTopWords(input);
        for (char b = 'a'; b <= 'z'; ++b) {
            input = input.substr(0, 1) + b;
            trie.findTopWords(input);
            for (char c = 'a'; c <= 'z'; ++c) {
                trie.findTopWords(input);
                input = input.substr(0, 2) + c;
            }
            input = input.substr(0, 1);
        }
        input = "";
    }
    timer = clock() - timer;
    
    printf("Retrieval time: %.3fms\n", (float)(timer * 1000) / CLOCKS_PER_SEC);
}