// Git location ~/workspace/Assignment_1_Word_Ladder/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WordQueue.hpp"

using namespace std;

int main()
{
    string start = "cat";
    string end = "may";
    string line;
    WordQueue partialSolutionQueue;
    vector<string> dictionary;  // used to store all the words from dictionary.txt
    vector<bool> used;
    
    ifstream inputFile ("dictionary.txt");
    if (!inputFile.is_open() || start.length() != end.length())
    {
        cout << "File could not be read... Or words are not the same length" << endl;
        cout << "Terminating..." << endl;
        return 0;
    }
    else
    {
        while (getline (inputFile, line))
        {
            if (line.length() == start.length())
            {
                dictionary.push_back(line);
            }
        }
        inputFile.close();
    }
    
    // Initialize to the size of the dictionary and set all the values to false because we
    // haven't used any of the words in the dictionary yet
    for (int i = 0; i < dictionary.size(); i++)
    {
        used.push_back(false);
    }
    
    
    vector<string> vStart = {start};
    partialSolutionQueue.enqueue(vStart);
    
    
    // Find the starting word in the dictionary and set it to used
    for (int i = 0; i < dictionary.size(); i++)
    {
        if (dictionary[i] == start)
        {
            used[i] = true;
        }
    }
    
    while (!partialSolutionQueue.isEmpty())
    {
        vector<string> possibleSolution = partialSolutionQueue.getFrontLadder();
        int size = possibleSolution.size()-1;
        if (possibleSolution[size] == end)
        {
            for (int i = 0; i < possibleSolution.size(); i++)
            {
                cout << possibleSolution[i] << endl;
            }
            return 0;
        }
        else
        {
            for (int j = 0; j < dictionary.size(); j++)
            {
                if (partialSolutionQueue.isWordConnected(possibleSolution[size], dictionary[j]) && !used[j])
                {
                    vector<string> copy = partialSolutionQueue.getFrontLadder();
                    copy.push_back(dictionary[j]);
                    partialSolutionQueue.enqueue(copy);
                    
                    used[j] = true;
                }
            }
        }
        partialSolutionQueue.dequeue();
    }
    
    
    
    
    
    return 0;
}
