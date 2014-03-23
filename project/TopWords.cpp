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
            *prev = *curr;
            *curr = (*curr)->next;
        }
        delete *prev;
    }
}


void TopWords::insert(BSTNode *bstnode)
{
    if (nullptr == m_pHead) {
        m_pHead = new TopWordNode;
        m_pHead->bstnode = bstnode;
        m_pHead->next = nullptr;
    }
    
    TopWordNode **prev = &m_pHead;
    TopWordNode **curr = &m_pHead->next;
    
    for (int i = 1; i < m_numWords; ++i) {
        if (nullptr == *curr) {
            *curr = new TopWordNode;
            (*curr)->bstnode = bstnode;
            (*curr)->next = nullptr;
            return;
        }
        else if (bstnode->weight > (*curr)->bstnode->weight) {
            TopWordNode *newNode = new TopWordNode;
            newNode->bstnode = bstnode;
            newNode->next = *curr;
            (*prev)->next = newNode;
            removeLastNode();
        }
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
            *prev = *curr;
            *curr = (*curr)->next;
        }
    }
    
    if (nullptr != *curr) {
        (*prev)->next = nullptr;
        delete *curr;
    }
}