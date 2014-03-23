//
//  TopWords.cpp
//  project
//
//  Created by Greg Paton on 3/23/14.
//  Copyright (c) 2014 Greg Paton. All rights reserved.
//

#include "TopWords.h"


TopWords::TopWords()
{
    m_pHead = nullptr;
    m_numWords = -1;
}


TopWords::~TopWords()
{
    if (nullptr != m_pHead) {
        TopWordNode **prev = &m_pHead;
        TopWordNode **curr = &m_pHead->next;
        
        while (nullptr != *curr) {
            delete *prev;
            prev = curr;
            curr = &(*curr)->next;
        }
        delete *prev;
    }
}


bool TopWords::init(int n)
{
    m_numWords = n;
    
    if (m_numWords < 0) {
        m_numWords = -1;
        return false;
    }
    
    return true;
}


void TopWords::insert(BWTNode *bwtnode)
{
    if (m_numWords < 0) {
        return;
    }
    
//    // If list is empty then add node
//    if (nullptr == m_pHead) {
//        m_pHead = new TopWordNode;
//        m_pHead->node = bwtnode;
//        m_pHead->next = nullptr;
//        return;
//    }
//    // If word is already in list then return
//    else if (0 == m_pHead->node->word.compare(bwtnode->word)) {
//        return;
//    }
    
    TopWordNode **prev = &m_pHead;
    TopWordNode **curr = &m_pHead;
    
    for (int i = 0; i < m_numWords; ++i) {
        // If list is not full then add node
        if (nullptr == *curr) {
            *curr = new TopWordNode;
            (*curr)->node = bwtnode;
            (*curr)->next = nullptr;
            return;
        }
        // If word is already in list then return
        else if (0 == (*curr)->node->word.compare(bwtnode->word)) {
            return;
        }
        // If node has a greater weight than that in the list
        // then insert the new node
        else if (bwtnode->weight > (*curr)->node->weight ||
                 (bwtnode->weight == (*curr)->node->weight &&
                 bwtnode->word.compare((*curr)->node->word) < 0)) {
            TopWordNode *next = *curr;
            *prev = new TopWordNode;
            (*prev)->node = bwtnode;
            (*prev)->next = next;
            removeLastNode();
            return;
        }
        else {
            prev = curr;
            curr = &(*curr)->next;
        }
    }
}


void TopWords::print()
{
    TopWordNode *curr = m_pHead;
    
    while (nullptr != curr) {
        printf("%s\n", curr->node->word.c_str());
        curr = curr->next;
    }
}


void TopWords::removeLastNode()
{
    if (nullptr == m_pHead) {
        return;
    }
    
    TopWordNode **prev = &m_pHead;
    TopWordNode **curr = &m_pHead->next;
    
    for (int i = 1; i < m_numWords; ++i) {
        if (nullptr == *curr) {
            return;
        }
        else {
            prev = curr;
            curr = &(*curr)->next;
        }
    }
    
    if (nullptr != *curr) {
        (*prev)->next = nullptr;
        delete *curr;
    }
}