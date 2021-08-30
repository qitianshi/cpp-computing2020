// Search.cpp
// Created on 8/7/20
// Running on macOS 10.15

// GNU General Public License version 3

// Sequential search and binary search algorithms.


#include <iostream>
#include <vector>
#include <utility>      // pair (data structure)
#include <stdlib.h>     // rand (randomizer), srand
#include <time.h>       // time (seed for randomizer)
#include <algorithm>    // sort
#include <chrono>       // steady_clock (high resolution chronograph)
using namespace std;

/// Prints the elements and original indexes in a vector.
/// @param vector The vector to be printed.
void displayVector(vector<pair<int, int>> vector) {
    for (int i = 0; i < vector.size(); ++ i) { cout << vector[i].second << ".\t" << vector[i].first << '\n'; }
}

/// Searches for the given target using sequential search.
///
/// Sequential search iterates through each element until it finds the target. This implementation only works lists of unique numbers. Sequential search has a time complexity of O(n).
/// @param searchElements The vector of elements in which to search.
/// @param target The element to search for.
/// @return The index of the search target in the original vector. Returns -1 if the target was not found.
int sequentialSearch(vector<pair<int, int>> searchElements, int target) {
    
    int i = 0;
    while (searchElements[i].first != target && i <= searchElements.size()) { i ++; }
    
    if (i > searchElements.size()) { return -1; }
    else { return i; }
    
}

/// Searches for the given target using binary search.
///
/// Binary search first sorts the list, then recursively compares the target with the middle element, and eliminates half the list where the target will not be found in, until it finds the target or it is left with a single element that is not the target (when the target is not found). Binary search has a time complexity of O(log n).
/// @param searchElements The vector of elements in which to search.
/// @param target The element to search for.
/// @param leftIndex The left index of the subarray.
/// @param rightIndex The right index of the subarray.
/// @return The index of the search target in the original vector. Returns -1 if the target was not found.
int binarySearch(vector<pair<int, int>> searchElements, int target, int leftIndex, int rightIndex) {
    
    if (rightIndex >= leftIndex) {
        
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        if (searchElements[middleIndex].first == target) { return searchElements[middleIndex].second; }     // Target has been found.
        else if (searchElements[middleIndex].first > target) { return binarySearch(searchElements, target, leftIndex, middleIndex - 1); }       // Target is in the left subarray.
        else { return binarySearch(searchElements, target, middleIndex + 1, rightIndex); }       // Target is in the right subarray.
        
    }
    
    return -1;      // This is only run when the list has been fully broken down but the target has not been found.
    
}

int main() {
    
    int vectorSize, searchMethod;
    
    while (true) {
        
        cout << "----------\n";
        
        cout << "Number of elements: ";
        cin >> vectorSize;
        if (vectorSize == 0) { break; }
        
        cout << "Search method: ";
        cin >> searchMethod;
        
        // Generates a list of unique integers in random order.
        int* randomizedNumbers = new int[vectorSize];
        for (int i = 0; i < vectorSize; ++ i) { randomizedNumbers[i] = i; }     // Fills each array with an incremental set of integers.
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < vectorSize; ++ i) { swap(randomizedNumbers[rand() % vectorSize], randomizedNumbers[rand() % vectorSize]); }     // Randomizes the order of elements in the array.
        
        vector<pair<int, int>> searchElements;        // Map is not used because this program is used to demonstrate binary search.
        for (int i = 0; i < vectorSize; ++ i) { searchElements.push_back(pair<int, int> (randomizedNumbers[i], i)); }       // Pushes the randomized array of numbers into the vector along with their original indexes.
        
        if (vectorSize <= 100) {
            cout << "\nOriginal list\n";
            displayVector(searchElements);
        }
        
        int searchTarget = rand() % vectorSize;     // Randomly generates a search target since its value is not important.
//        int searchTarget = vectorSize + 1;        // Use this to test behavior for a missing target.
        int targetFoundAt = -1;
        string searchType;
        auto start = chrono::steady_clock::now();
        
        switch (searchMethod) {

            // Sequential search
            case 1: {
                searchType = "Sequential search";
                targetFoundAt = sequentialSearch(searchElements, searchTarget);
                break;
            }
                
            // Binary search
            case 2: {
                searchType = "Binary search";
                sort(searchElements.begin(), searchElements.end());     // Binary search requires that the list be sorted.
                targetFoundAt = binarySearch(searchElements, searchTarget, 0, vectorSize - 1);
                break;
            }

            default: {
                cout << "\nInvalid selection.\n";
                break;
            }

        }
        
        auto end = chrono::steady_clock::now();
        
        // Checks that the selected search method is valid.
        if (searchType != "") {
            
            cout << '\n' << searchType;
            cout << "\n'" << searchTarget << "' ";
            
            if (targetFoundAt == -1) { cout << "was not found."; }      // Search algorithms return -1 if the target was not found.
            else { cout << "was found at index " << targetFoundAt << '.'; }
            
            cout << "\nCompleted in " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs.\n";
            
        }
        
        searchType = "";
        targetFoundAt = -1;
        
        cout << '\n';
        
    }
    
    return 0;
    
}
