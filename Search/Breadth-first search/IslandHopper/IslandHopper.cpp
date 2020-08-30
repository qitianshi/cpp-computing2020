// IslandHopper.cpp
// Created on 26/8/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Finds the shortest path between connected islands.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>    // sort
#include <queue>
using namespace std;

/// An island with bridges to other islands.
struct Island {
    
    int distanceFromOrigin;             // The number of bridges between this island and the origin island.
    bool wasVisited;                    // Used in the breadth-first search alogrithm to check if the island has already been passed.
    vector<Island*> connections;        // Pointers are used to symbolically represent the connections.
    
    // Sets default values for each instance.
    Island() {
        wasVisited = false;
        distanceFromOrigin = -1;
    }
    
};

int main() {
    
    ifstream fin("data.txt");
    
    int numberOfIslands, numberOfBridges;
    fin >> numberOfIslands >> numberOfBridges;
    
    vector<Island> islands(numberOfIslands);        // Stores the islands in a vector, using the custom constructor provided with the Island structure.
    
    // Reads each bridge and stores it into each island.
    for (int i = 0; i < numberOfBridges; ++ i) {
        
        int bridgeOrigin, bridgeDestination;
        fin >> bridgeOrigin >> bridgeDestination;
        bridgeOrigin --; bridgeDestination --;      // Islands are numbered from 1; here they are converted to zero-based numbering.

        
        // Stores each bridge connection as a pointer. Since bridges are bidirectional, the connection is stored for both islands.
        islands[bridgeOrigin].connections.push_back(&islands[bridgeDestination]);
        islands[bridgeDestination].connections.push_back(&islands[bridgeOrigin]);
        
    }
    
    int origin, destination;
    fin >> origin >> destination;
    origin --; destination --;      // Islands are numbered from 1; here they are converted to zero-based numbering.
    
    // Initializes the origin island.
    islands[origin].distanceFromOrigin = 0;
    islands[origin].wasVisited = true;
    
    // Stores the upcoming sequence of islands to be visited by the search algorithm.
    queue<Island*> unsearchedIslands;
    unsearchedIslands.push(&islands[origin]);
    
    // Finds the minimum distance of each island from the origin.
    while (!unsearchedIslands.empty()) {
        
        Island* thisIsland = unsearchedIslands.front();
        
        // Adds this island's connections to the end of the queue.
        for (vector<Island*>::iterator itr = (*thisIsland).connections.begin(); itr != (*thisIsland).connections.end(); ++ itr) {
            if (!(**itr).wasVisited) {      // If the island has already been visited, the optimal path has already been found.
                
                (**itr).distanceFromOrigin = (*thisIsland).distanceFromOrigin + 1;      // Each connected island is one bridge further from the origin.
                (**itr).wasVisited = true;
                
                unsearchedIslands.push(*itr);
                
            }
        }
        
        unsearchedIslands.pop();
        
    }
    
    cout << islands[destination].distanceFromOrigin << '\n';
    
    return 0;
    
}
