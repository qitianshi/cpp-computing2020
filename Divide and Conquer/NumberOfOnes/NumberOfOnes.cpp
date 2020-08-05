// NumberOfOnes.cpp
// Created on 5/8/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Finds the number of 1s in a sorted sequence.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // lower_bound
#include <chrono>       // steady_clock
using namespace std;

int main() {
    
    ifstream fin("data.txt");
    
    vector<int> numbers;
    char input;     // Inputs into a char so that only one character is read at a time.
    while (fin >> input) {
        int number = input - '0';       // Casts the char into an int.
        numbers.push_back(number);
    }
    
    auto start = chrono::steady_clock::now();       // Begins timing the code.

    vector<int>::iterator lower = lower_bound(numbers.begin(), numbers.end(), 1);       // Finds the first occurrence of 1.
    cout << numbers.size() - distance(numbers.begin(), lower);      // Finds the total number of 1s since every character after the first 1 is also a 1.
    
    auto end = chrono::steady_clock::now();
    cout << "\nCompleted in " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs.\n";

    return 0;
    
}
