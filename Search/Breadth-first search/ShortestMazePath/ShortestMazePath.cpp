// ShortestMazePath.cpp
// Created on 1/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the length of the shortest path between two positions in a maze.


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>      // pair
#include <string>       // to_string
using namespace std;

/// A position in the maze, either a space or a wall.
struct Position {
    
    int distanceFromOrigin;     // Number of movements between this position and the origin.
    bool visitable;             // Whether this position is visitable by the search algorithm. Walls and already visited positions are unvisitable. There is no need to explicitly distinguish walls from spaces.
    
};

int main() {
    
    ifstream fin("data.txt");
    
    int height, width;
    fin >> height >> width;
    
    Position maze[height][width];                                           // Stores the maze in an array. FIXME: Use a dynamically allocated array.
    pair<Position*, Position*> targets = {&maze[0][0], &maze[0][0]};        // Positions are stored as y- and x-coordinates.
    for (int i = 0; i < height; ++ i) for (int j = 0; j < width; ++ j) {
        
        char input;
        fin >> input;
        
        switch (input) {
                
            // Wall
            case 'x': {
                maze[i][j] = {-1, false};       // Walls are immediately marked as unvisitable.
                break;
            }
                
            // Space
            case '-': {
                maze[i][j] = {-1, true};
                break;
            }
                
            // Target
            case '*': {
                
                // Checks whether the first target is taken. Works even when first target is {0, 0}.
                if (targets.first == &maze[0][0]) { targets.first = &(maze[i][j]); }
                else { targets.second = &(maze[j][i]); }
                
                maze[i][j] = {-1, true};
                
                break;
                
            }
                
            default: { break; }
                
        }
        
    }
    
    // Unsearched positions are stored in a queue.
    queue<Position*> unsearchedPositions;
    
    // Sets the first target as the origin.
    (*targets.first).distanceFromOrigin = 0;
    (*targets.first).visitable = false;
    unsearchedPositions.push(targets.first);
    
    while (!unsearchedPositions.empty()) {
        
        // Possible movement combinations
        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {1, 0, -1, 0};
        
        Position* thisPosition = unsearchedPositions.front();
        
        // Breaks out of the loop if the destination has been found. Since the graph is unweighted, the first visit is the shortest path.
        if (thisPosition == targets.second) { break; }
        
        // Adds this position's neighbors to the queue.
        for (int i = 0; i < 4; ++ i) {
            
            #define nextY ((thisPosition - &maze[0][0]) / width + dy[i])
            #define nextX ((thisPosition - &maze[0][0]) % width + dx[i])
            
            // Continues onwards if the next position does not exist.
            if ( (nextY < 0) || (nextY > height - 1) || (nextX < 0) || (nextX > width - 1) ) { continue; }
            
            if(maze[nextY][nextX].visitable) {
                
                (maze[nextY][nextX]).distanceFromOrigin = (*thisPosition).distanceFromOrigin + 1;       // Each position is one spot further away from the origin.
                (maze[nextY][nextX]).visitable = false;
                
                unsearchedPositions.push(&(maze[nextY][nextX]));
                
            }
            
            #undef nextY
            #undef nextX
            
        }
        
        unsearchedPositions.pop();
        
    }
    
    #define result ((*targets.second).distanceFromOrigin)
    cout << (result == -1 ? "No path" : to_string(result)) << '\n';     // Ternary operator changes the output depending on the result.
    #undef result
    
    return 0;
    
}
