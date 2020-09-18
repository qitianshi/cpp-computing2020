// MaximumSubsequence.cpp
// Created on 15/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the contiguous subsequence with the largest sum.


#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>     // INT_MIN
using namespace std;

int main() {
    
    ifstream fin("data.txt");
    vector<int> runningTotal;

    // Stores the running total of the sequence.
    {
        int input;
        while (fin >> input) { runningTotal.push_back((runningTotal.empty() ? input : runningTotal[runningTotal.size() - 1] + input)); }
    }
    
    int maximum = INT_MIN;
    for (int i = 1; i <= runningTotal.size() - 1; ++ i) for (int j = 0; j < runningTotal.size() - i; ++ j) {
        if (runningTotal[j + i] - runningTotal[j] > maximum) { maximum = runningTotal[j + i] - runningTotal[j]; }
    }
    
    cout << maximum << '\n';
    
    return 0;
    
}
