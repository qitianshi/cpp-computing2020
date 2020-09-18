// LongestIncreasingSubsequence.cpp
// Created on 16/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the longest increasing subsequence in a sequence of numbers.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    ifstream fin("data.txt");
    
    // Stores the sequence in a vector.
    vector<int> sequence;
    {
        int input;
        while (fin >> input) { sequence.push_back(input); }
    }
    
    vector<int> longestIncreasing;      // The length of the LIS that ends at each position.
    longestIncreasing.push_back(1);     // Pushes 1 for the zeroth element because there cannot be longer subsequences.
    
    for (int i = 1; i < sequence.size(); ++ i) {
        
        longestIncreasing.push_back(1);     // Initial size
        
        for (int j = 0; j < i; ++ j) {      // Loops through previous positions in the sequence.
            if ( (sequence[i] > sequence[j]) && (longestIncreasing[i] < longestIncreasing[j] + 1) ) { longestIncreasing[i] = longestIncreasing[j] + 1; }
        }
        
    }
    
    cout << *max_element(longestIncreasing.begin(), longestIncreasing.end()) << '\n';
    
    return 0;
    
}
