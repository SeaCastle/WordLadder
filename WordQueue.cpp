//
//  WordQueue.cpp
//  Cs3 Assignment 1
//
//  Created by Spencer Peterson on 1/19/17.
//  Copyright © 2017 StickmanMafia. All rights reserved.
//

#include "WordQueue.hpp"


WordQueue::WordQueue()
{
    head = NULL;
    tail = NULL;
}

void WordQueue::enqueue(vector<string> newWords)
{
    Node* temp = new Node();
    temp->wordLadder = newWords;
    temp->next = nullptr;
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        tail->next = temp;
    }
    tail = temp;
}

bool WordQueue::isEmpty()
{
    bool isEmpty = false;
    
    if (head == NULL)
    {
        isEmpty = true;
    }
    
    return isEmpty;
}

bool WordQueue::isWordConnected(string current, string test)
{
    bool isConnected = false;
    int length = current.length();
    int i = 0;
    
    // Search for any words that differ from the current word by 1 letter starting with
    // the first letter and moving toward the end 1 letter at a time
    while (!isConnected && i < length)
    {
        // This first and second if statements are unique for allowing the changing of the first and last letter
        if (i == 0 && current.substr(i+1, length) == test.substr(i+1, length))
        {
            isConnected = true;
        }
        else if (i == length-1 && current.substr(0, i) == test.substr(0, i))
        {
            isConnected = true;
        }
        else if (current.substr(0, i) == test.substr(0, i) && current.substr(i+1, length) == test.substr(i+1, length))
        {
            isConnected = true;
        }
        
        ++i;
    }
    
    return isConnected;
}

void WordQueue::dequeue()
{
    Node* temp = new Node();
    
    if (head == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

vector<string> WordQueue::getFrontLadder()
{
    if (head == nullptr)
    {
        vector<string> empty = {"empty"};
        return empty;
    }
    else
    {
        return head->wordLadder;
    }
}