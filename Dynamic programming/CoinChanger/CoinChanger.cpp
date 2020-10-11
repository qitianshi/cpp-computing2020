// CoinChanger.cpp
// Created on 5/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds every combination of a set of coins that add to a given total.


#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int main() {
    
    ifstream fin("data.txt");
    
    int numberOfDenominations, targetSum;
    fin >> numberOfDenominations >> targetSum;
    
    int *denominations = new int[numberOfDenominations];
    for (int i = 0; i < numberOfDenominations; ++ i) { fin >> denominations[i]; }
    
    // The value of each cell [i][j] represents the number of ways to reach the sum i using coins of denominations[0...j-1].
    // The size of the array is +1 on both dimensions because we need to include the row for 0 coins and the column for a sum of 0.
    // Thus, each row j corresponds to denominations[j-1] to offset the presence of the first row with 0 value, which isn't included in denominations.
    int combinations[targetSum + 1][numberOfDenominations + 1];
    
    // Sets base cases first.
    for (int i = 0; i <= numberOfDenominations; ++ i) { combinations[0][i] = 1; }    // 1 way of getting to a total of 0: with 0 coins.
    for (int i = 1; i <= targetSum; ++ i) { combinations[i][0] = 0; }                // 0 ways of getting to any amount if there are no denominations to choose from.
    
    // Calculates the values for each cell in the table.
    for (int i = 1; i <= targetSum; ++ i) for (int j = 1; j <= numberOfDenominations; ++ j) {
        
        // A combination can either include the current denomination or exlude it: e.g. 1+1+1 (exludes) and 3 (includes).
        int combosIncludingThis, combosExludingThis;
        
        if (i < denominations[j - 1]) { combosIncludingThis = 0; }                   // If the desired value is less than the current denomination, it's impossible to create a combo including this denomination.
        else { combosIncludingThis = combinations[i - denominations[j - 1]][j]; }    // If this denomination is used, the total sum decreases by an amount equal to the value of this denomination.
        
        combosExludingThis = combinations[i][j - 1];        // The number of combos that reach this same value without using this denomination.
        
        combinations[i][j] = combosIncludingThis + combosExludingThis;
        
    }
    
    cout << combinations[targetSum][numberOfDenominations] << '\n';
    
    return 0;
    
}
