// SumOfPairs.cpp
// Created on 8/7/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Finds unique pairs of integers that sum to a given number.


#include <iostream>
#include <vector>
#include <utility>      // Pair data structure
#include <fstream>      // Reading and writing to files.
#include <chrono>       // High resolution chronograph to time code.
using namespace std;

/// Determines if the given target is present using binary search.
/// @param searchElements The array of elements in which to search.
/// @param target The element to search for.
/// @param leftIndex The left index of the subarray.
/// @param rightIndex The right index of the subarray.
/// @return Whether the targest exists in the given array.
bool binaryFind(int searchElements[], int target, int leftIndex, int rightIndex) {
    
    if (rightIndex >= leftIndex) {
        
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        if (searchElements[middleIndex] == target) { return true; }     // Target has been found.
        else if (searchElements[middleIndex] > target) { return binaryFind(searchElements, target, leftIndex, middleIndex - 1); }       // Target is in the left subarray.
        else { return binaryFind(searchElements, target, middleIndex + 1, rightIndex); }       // Target is in the right subarray.
        
    }
    
    return false;      // This is only run when the list has been fully broken down but the target has not been found.
    
}

/// Finds unique pairs of integers that sum to a given number.
/// @param sequence The array of numbers in which to search for pairs.
/// @param arraySize The size of the array.
/// @param targetValue The target value.
/// @return A vector of pairs containing unique pairs of integers.
vector <pair <int, int>> searchForPairs(int sequence[], int arraySize, int targetValue) {
    
    sort(sequence, sequence + arraySize);           // Sorts the array.
    
    vector <pair <int, int>> discoveredPairs;       // Creates a vector to store results.
    int i = -1,
        previousValue = INT_MIN,
        searchTarget;
    
    while (sequence[i + 1] <= targetValue / 2) {        // If the value is more than half of the target, all pairs have already been found.
        
        i ++;
        if (sequence[i] == previousValue) { continue; }     // Avoids repeated pairs.
        
        searchTarget = targetValue - sequence[i];       // Calculates the value that needs to be found.
        
        // Adds the pair if it exists in the array.
        if (binaryFind(sequence, searchTarget, 0, arraySize - 1)) {
            
            pair <int, int> newEntry;
            newEntry.first = sequence[i];
            newEntry.second = searchTarget;
            
            discoveredPairs.push_back(newEntry);
            
        }
        
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
    
    vector <pair <int, int>> results;       // Creates a vector of pairs to store results.
    results = searchForPairs(sequence, arraySize, targetValue);
    for (int i = 0; i < results.size(); ++ i) { cout << results[i].first << ' ' << results[i].second << '\n'; }
    
    return 0;
    
}
