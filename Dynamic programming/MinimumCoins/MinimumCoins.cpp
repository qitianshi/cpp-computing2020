// MinimumCoins.cpp
// Created on 23/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the minimum number of coins that add to a given total.


#include <iostream>
#include <fstream>
#include <limits.h>     // INT_MAX
using namespace std;

int findMinimum(int denominations[], int numberOfDenominations, int* minimumCoins[], int total, int remainingAmount) {
    
    if (remainingAmount == 0) { return 0; }
    
    int minimumNumber = INT_MAX;
    
    for (int i = 0; i < numberOfDenominations; ++ i) {
        if (denominations[i] <= remainingAmount) {
            int solution = findMinimum(denominations, numberOfDenominations, minimumCoins, total, remainingAmount - denominations[i]);
            if (solution != INT_MAX && solution + 1 < minimumNumber) { minimumNumber = solution + 1; }
        }
    }
    
    return minimumNumber;
    
}

int main() {
    
    ifstream fin("data.txt");
    
    int numberOfDenominations, total;
    fin >> numberOfDenominations >> total;
    
    int* minimumCoins = new int[total];
    minimumCoins[0] = 0;
    for (int i = 1; i < total; ++ i) { minimumCoins[i] = INT_MAX; }
    
    int* denominations = new int[numberOfDenominations];
    for (int i = 0; i < numberOfDenominations; ++ i) {
        int input;
        fin >> input;
        denominations[i] = input;
    }
    
    cout << findMinimum(denominations, numberOfDenominations, &minimumCoins, total, total) << '\n';
    
    return 0;
    
}
