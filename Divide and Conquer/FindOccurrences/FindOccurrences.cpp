// FindOccurrences.cpp
// Created on 29/7/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Finds the first and last occurrence of a given integer in a list.


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum occurrence { first, last };        // Possible cases for the target occurrence in findNumber().

/// Finds the first or last occurrence of an integer in a sorted list of integers.
///
/// This is a modified binary search algorithm. In addition to checking for the element's value, it will also check its neighbors to ensure that it is the first or last occurrence.
/// @param searchList The list to search in.
/// @param leftIndex The left index of the sublist.
/// @param rightIndex The right index of the sublist.
/// @param target The number to search for.
/// @param targetOccurrence Specifies whether the first or last occurrence of the number should be searched for.
int findNumber(vector<int> searchList, int leftIndex, int rightIndex, int target, occurrence targetOccurrence) {
    
    if (rightIndex >= leftIndex) {
        
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        if (searchList[middleIndex] == target) {        // The target has been found but its neighbors need to be checked.
            switch (targetOccurrence) {
                    
                case first: {
                    
                    if (searchList[middleIndex - 1] != target) { return middleIndex; }                                  // The first occurrence has been found.
                    else { return findNumber(searchList, leftIndex, middleIndex - 1, target, targetOccurrence); }        // Continues to search on the left.
                    break;
                    
                }
                    
                case last: {
                    
                    if (searchList[middleIndex + 1] != target) { return middleIndex; }                                  // The last occurrence has been found.
                    else { return findNumber(searchList, middleIndex + 1, rightIndex, target, targetOccurrence); }       // Continues to search on the right.
                    break;
                    
                }
                    
            }
        }
        
        if (searchList[middleIndex] > target) { return findNumber(searchList, leftIndex, middleIndex - 1, target, targetOccurrence); }       // Target is in the left subarray.
        
        return findNumber(searchList, middleIndex + 1, rightIndex, target, targetOccurrence);        // Target is in the right subarray/
        
    }
    
    return -1;
}

int main() {
    
    ifstream fileIn("data.txt");
    
    int target;
    fileIn >> target;
    
    // Pushes the list into a vector.
    vector<int> searchList;
    while (!fileIn.eof()) {
        int input;
        fileIn >> input;
        searchList.push_back(input);
    }
    searchList.pop_back();      // Removes the last extraneous element.
    
    const int firstOccurrence = findNumber(searchList, 0, static_cast<int>(searchList.size() - 1), target, first);
    const int secondOccurrence = findNumber(searchList, 0, static_cast<int>(searchList.size() - 1), target, last);
    
    if (firstOccurrence == -1 || secondOccurrence == -1) { cout << -1 << '\n'; }        // If either result is -1, the target wasn't found.
    else { cout << firstOccurrence << '\n' << secondOccurrence << '\n'; }
    
    return 0;
    
}
