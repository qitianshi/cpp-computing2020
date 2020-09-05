// RoadNetwork.cpp
// Created on 11/8/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds cities that are not connected in a road network.


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct City {
    vector<int> destinations;
    vector<int> visitedCities;
};

void searchCities(vector<City> &roadNetwork, int searchRoot, int targetCity) {
    
    vector<int>::iterator itr = roadNetwork[searchRoot].destinations.begin();
    
    // Goes down the list of cities in the destination cities.
    while (itr != roadNetwork[searchRoot].destinations.end()) {
        
        if ( find(roadNetwork[targetCity].visitedCities.begin(), roadNetwork[targetCity].visitedCities.end(), *itr) == roadNetwork[targetCity].visitedCities.end() ) {      // If this city has not already been visited
            
            roadNetwork[targetCity].visitedCities.push_back(*itr);        // This city has been visited by the algorithm.
            searchCities(roadNetwork, *itr, targetCity);                  // Continues the search algorithm with the current city.
            
        }
        
        itr ++;
        
    }
    
}

int main() {
    
    ifstream fin("data.txt");
    
    int numberOfCities, numberOfRoads;
    fin >> numberOfCities >> numberOfRoads;
    
    // Creates a vector roadNetwork with a preset number of elements.
    vector<City> roadNetwork(numberOfCities);
    
    // Inputs each route as an origin and destination.
    for (int i = 0; i < numberOfRoads; ++ i) {
        
        int origin, destination;
        fin >> origin >> destination;
        
        roadNetwork[origin].destinations.push_back(destination);
        
    }
    
    // Runs the search algorithm and outputs the result for each city.
    for (int i = 0; i < numberOfCities; ++ i) {
        
        searchCities(roadNetwork, i, i);
        
        cout << i << ": ";
        for (int j = 0; j < numberOfCities; ++ j) {
            if ( find(roadNetwork[i].visitedCities.begin(), roadNetwork[i].visitedCities.end(), j) == roadNetwork[i].visitedCities.end() &&  i != j) { cout << j << ' '; }      // This city is unreachable if it is not in the list of visited cities.
        }
        
        cout << '\n';
        
    }
    
    return 0;
    
}
