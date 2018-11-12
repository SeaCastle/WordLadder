//
//  WordQueue.hpp
//  Cs3 Assignment 1
//
//  Created by Spencer Peterson on 1/19/17.
//  Copyright © 2017 StickmanMafia. All rights reserved.
//

#ifndef WordQueue_hpp
#define WordQueue_hpp

#include <stdio.h>

#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    vector<string> wordLadder;
    Node* next;
    Node* prev;
};

class WordQueue
{
private:
    Node* head;
    Node* tail;
    
public:
    WordQueue();
    bool isEmpty();
    bool isWordConnected(string current, string test);
    void enqueue(vector<string> newWords);
    void dequeue();
    vector<string> getFrontLadder();
};


#endif /* WordQueue_hpp */
