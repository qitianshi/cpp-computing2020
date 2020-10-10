// MaximumSubsequence.cpp
// Created on 15/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the largest sum for a contiguous subsequence.


#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>     // INT_MIN
using namespace std;

int main() {
    
    ifstream fin("data.txt");
    vector<int> sequence, results;

    // Stores sequence in a vector.
    {
        int input;
        while (fin >> input) { sequence.push_back(input); }
    }

    int maximumSum = INT_MIN, runningTotal = 0;     // maximumSum is set to INT_MIN for if all of the numbers in the sequence are zero.
    for (vector<int>::iterator itr = sequence.begin(); itr != sequence.end(); ++ itr) {
        
        runningTotal = max( (runningTotal + *itr) , *itr );     // If we encounter a single value greater than the entire runningTotal, a new sequence begins here.
        maximumSum = max(maximumSum, runningTotal);             // maximumSum takes the current runningTotal if it's larger.
        
    }

    cout << maximumSum << '\n';
    for(vector<int>::iterator itr = results.begin(); itr != results.end(); ++ itr) { cout << *itr << ' '; }

    return 0;
    
}
