// LongestSubsequence.cpp
// Created on 14/7/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the longest non-decreasing subsequence within a given range.


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>        // lower_bound, upper_bound
using namespace std;

int main() {
    
    ifstream fin("data.txt");
    
    int rows, columns;
    fin >> rows;
    fin >> columns;
    
    vector<vector<int>> sequence;           // Stores the sequence in a vector of vectors.
    for (int i = 0; i < rows; ++ i) {       // Pushes each row into the sequence.
        
        vector<int> inputVector;
        
        for (int j = 0; j < columns; ++ j) {
            int input;
            fin >> input;
            inputVector.push_back(input);
        }
        
        sequence.push_back(inputVector);
        
    }
    
    int lowerValue, upperValue;
    fin >> lowerValue;
    fin >> upperValue;
    
    vector<vector<int>> results;
    int longestSubsequence = 0;     // The length of the current longest subsequence.
    for (int i = 0; i < rows; ++ i) {
        
        vector<int> inputVector;
        vector<int>::iterator lower, upper;     // Points to the lower and upper bounds of the subsequence.
    
        lower = lower_bound(sequence[i].begin(), sequence[i].end(), lowerValue);        // Finds the first element that is greater than or equal to the given value.
        upper = upper_bound(sequence[i].begin(), sequence[i].end(), upperValue);        // Finds the first element that is greater than the given value.
        
        for(vector<int>::iterator itr = lower; itr != upper; ++ itr) { inputVector.push_back(*itr); }       // Extracts the elements from the sequence.
        
        if (inputVector.size() > longestSubsequence) {      // Resets the result output if the new sequence is shorter.
            results.clear();
            results.push_back(inputVector);
            longestSubsequence = static_cast<int>(inputVector.size());      // Casts .size() to type int.
        } else if (inputVector.size() == longestSubsequence) { results.push_back(inputVector); }
        
    }
    
    if (results.empty()) { cout << "No result"; }
    
    // Prints the elements in each vector.
    for (int i = 0; i < results.size(); ++ i) {
        for (int j = 0; j < results[i].size(); ++ j) { cout << results[i][j] << ' '; }
        cout << '\n';
    }
    
    return 0;
    
}
