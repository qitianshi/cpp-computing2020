// Fibonacci.cpp
// Created on 5/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the nth Fibonacci number.


#include <iostream>
#include <utility>
#include <chrono>       // steady_clock
#include <math.h>       // pow
using namespace std;

int main() {
    
    int target;
    cin >> target;
    
    auto start = chrono::steady_clock::now();       // Starts a timer.
    
    unsigned long long result = (target <= 0 ? 0 : 1);      // Edge case for the zeroth or negative Fibonacci number.
    {
        
        pair<unsigned long long, unsigned long long> previousNumbers = {1, 1};      // The previous number, and the one before it.
        for (int i = 2; i < target; ++ i) {     // The loop is skipped for the first two Fibonacci numbers; the result remains at 1.
            
            result = previousNumbers.first + previousNumbers.second;
            if (target > 93) { result %= static_cast<unsigned long long>(pow(10.0, 18.0)); }        // The 93rd Fibonacci number is the largest that can be stored in a 64-bit unsigned integer.
            
            // Refreshes the stored previous numbers with new values.
            swap(previousNumbers.first, previousNumbers.second);
            previousNumbers.first = result;
            
        }
        
    }
    
    auto end = chrono::steady_clock::now();         // Ends the timer.
    
    if (target > 93) { cout << "Last 18 digits of "; }
    cout << "Fibonacci number " << target << ": " << result << '\n';
    cout << "Completed in " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs.\n";
    
    return 0;
    
}
