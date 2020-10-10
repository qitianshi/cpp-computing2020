// MinimumCoins.cpp
// Created on 23/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the minimum number of coins that add to a given total.


#include <iostream>
#include <fstream>
#include <limits.h>     // INT_MAX
using namespace std;

/// Finds the minimum number of coins that can add to a given total.
/// @param denominations An array of the possible denominations of coins.
/// @param numberOfDenominations The number of denominations.
/// @param remainingAmount The remaining unallocated amount. Initial value should be equal the total amount.
int findMinimum(int denominations[], int numberOfDenominations, int remainingAmount) {
    
    if (remainingAmount == 0) { return 0; }     // Function returns if everything has been allocated.
    
    int minimumNumber = INT_MAX;        // Initializes minimumNumber with INT_MAX so it will take the value of the first result.
    
    for (int i = numberOfDenominations - 1; i >= 0; -- i) {     // Tries the largest denominations first.
        if (denominations[i] <= remainingAmount) {      // Any denomination larger than the remainder is ignored.
            int solution = findMinimum(denominations, numberOfDenominations, remainingAmount - denominations[i]);       // Recursively breaks down the remainder until nothing remains.
            minimumNumber = min(minimumNumber, solution + 1);       // Updates its value if the new solution is better.
        }
    }
    
    return minimumNumber;
    
}

int main() {
    
    ifstream fin("data.txt");
    
    int numberOfDenominations, total;
    fin >> numberOfDenominations >> total;
    
    // Stores the denominations in an array.
    int* denominations = new int[numberOfDenominations];
    for (int i = 0; i < numberOfDenominations; ++ i) {
        int input;
        fin >> input;
        denominations[i] = input;
    }
    
    cout << findMinimum(denominations, numberOfDenominations, total) << '\n';
    
    return 0;
    
}
