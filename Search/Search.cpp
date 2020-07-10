// Searching.cpp
// Created on 8/7/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Sequential search and binary search algorithms.


#include <iostream>
#include <vector>
#include <utility>      // Pair data structure
#include <stdlib.h>     // Randomizer
#include <time.h>       // Time, acts as seed for randomizer.
using namespace std;

int main() {
    
    vector <pair <int, int>> searchElements;
    int vectorSize, searchMethod;
    
    cout << "Number of elements: ";
    cin >> vectorSize;
    cout << "Search method: ";
    cin >> searchMethod;
    
    // Generates a list of unique integers in random order.
    int *randomizedNumbers = new int[vectorSize];
    for (int i = 0; i < vectorSize; ++ i) { randomizedNumbers[i] = i; }     // Fills each array with an incremental set of integers.
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < vectorSize; ++ i) { swap(randomizedNumbers[rand() % vectorSize], randomizedNumbers[rand() % vectorSize]); }     // Randomizes the order of elements in the array.
    
    // Pushes the randomized array of numbers into the vector along with their original indexes.
    for (int i = 0; i < vectorSize; ++ i) {
        
        pair <int, int> newEntry;
        newEntry.first = randomizedNumbers[i];      // Value
        newEntry.second = i;                        // Original index
        
        searchElements.push_back(newEntry);
        
    }
    
    return 0;
    
}
