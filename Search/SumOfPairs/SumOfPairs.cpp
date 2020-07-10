// SumOfPairs.cpp
// Created on 8/7/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Finds unique pairs of integers that sum to a given number.


#include <iostream>
#include <map>
#include <fstream>      // fstream (read from files)
#include <algorithm>    // find (find elements in arrays), sort
using namespace std;

/// Finds unique pairs of integers that sum to a given number.
/// @param sequence The array of numbers in which to search for pairs.
/// @param arraySize The size of the array.
/// @param targetValue The target value.
/// @return A vector of pairs containing unique pairs of integers.
map<int, int> searchForPairs(int sequence[], int arraySize, int targetValue) {
    
    sort(sequence, sequence + arraySize);           // Sorts the array.
    
    map<int, int> discoveredPairs;       // Creates a vector to store results.
    int i = -1,
        previousValue = INT_MIN,
        searchTarget;
    
    while (sequence[i + 1] <= targetValue / 2) {        // If the value is more than half of the target, all pairs have already been found.
        
        i ++;
        if (sequence[i] == previousValue) { continue; }     // Avoids repeated pairs.
        
        searchTarget = targetValue - sequence[i];       // Calculates the value that needs to be found.
        
        // Adds the pair if it exists in the array.
        if (find(sequence, sequence + arraySize, searchTarget) != sequence + arraySize) { discoveredPairs.insert(pair<int, int> (sequence[i], searchTarget)); }
        
        previousValue = sequence[i];
        
    }
    
    return discoveredPairs;
    
}

int main() {
    
    ifstream fileIn("data.txt");
    
    int arraySize;
    fileIn >> arraySize;
    
    int sequence[arraySize];
    for (int i = 0; i < arraySize; ++ i) { fileIn >> sequence[i]; }
    
    int targetValue;
    fileIn >> targetValue;
    
    map<int, int> results;       // Creates a vector of pairs to store results.
    results = searchForPairs(sequence, arraySize, targetValue);
    if (results.empty()) { cout << "None\n"; }
    else {
        for (map<int, int>::iterator itr = results.begin(); itr != results.end(); ++ itr) { cout << itr -> first << ' ' << itr -> second << '\n'; }
    }
    
    return 0;
    
}
