// LetterGrid.cpp
// Created on 25/8/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the largest contiguous area of letters in a grid.


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

/// Finds the size of a contiguous area of characters.
///
/// A variable of type `int` must be declared outside this function and initially assigned the value `0`. The `size` parameter is a pointer to this variable.
/// @param grid A two-dimensional vector of the grid of characters.
/// @param yCoordinate The y-coordinate of the grid position to be checked.
/// @param xCoordinate The x-coordinate of the grid position to be checked.
/// @param target The character to be found.
/// @param size A pointer to the variable that stores the size of the letter.
/// @param visited A pointer to the two-dimensional vector of visited grid positions.
void sizeOfContiguousArea(vector<vector<char>> grid, int yCoordinate, int xCoordinate, char target, int* size, vector<vector<bool>>* visited) {

    // Possible movement combinations.
    int dy[8] = {1,  1,  1,  0,  -1, -1, -1, 0};
    int dx[8] = {-1, 0,  1,  1,  1,  0,  -1, -1};

    // Checks if the requested coordinate is out of bounds.
    if ( (xCoordinate < 0) || (xCoordinate > grid[yCoordinate].size() - 1) || (yCoordinate < 0) || (yCoordinate > grid.size() - 1) ) { return; }
    
    if ((*visited)[yCoordinate][xCoordinate]) { return; }
    
    if (grid[yCoordinate][xCoordinate] == target) {
        
        // Marks the position as visited.
        (*visited)[yCoordinate][xCoordinate] = true;
        
        (*size) ++;
        
        for (int i = 0; i < 8; ++ i) { sizeOfContiguousArea(grid, yCoordinate + dy[i], xCoordinate + dx[i], target, size, visited); }
        
    }

    return;

}

int main() {
    
    ifstream fin("data.txt");
    
    int rows, columns;
    fin >> rows >> columns;
    
    vector<vector<char>> grid;      // Stores the grid in a two-dimensional vector.
    vector<vector<bool>> visited;   // Stores the positions that have already been visited.
    map<char, int> results;         // Stores the result for each letter.
    
    for (int i = 0; i < rows; ++ i) {
        
        // Temporarily creates one-dimensional vectors to be pushed later.
        vector<char> newGridRow;
        vector<bool> newVisitedRow;
        
        for (int j = 0; j < columns; ++ j) {
            
            // Takes the next character from the grid.
            char newInput;
            fin >> newInput;
            newGridRow.push_back(newInput);
            
            // Marks the grid position as unvisited.
            newVisitedRow.push_back(false);
            
            // Creates a new key in the map if it doesn't already exist.
            if ( newInput != '.' && results.find(newInput) == results.end() ) { results.insert({ newInput, 0 }); }
            
        }
        
        // Pushes the temporarily created rows.
        grid.push_back(newGridRow);
        visited.push_back(newVisitedRow);
        
    }
    
    // Finds the size of each contiguous area.
    for (int i = 0; i < rows; ++ i) for (int j = 0; j < columns; ++ j) {
        
        int size = 0;
        if ( grid[i][j] != '.' && !visited[i][j] ) {
            sizeOfContiguousArea(grid, i, j, grid[i][j], &size, &visited);
            if ( results[grid[i][j]] < size ) { results[grid[i][j]] = size; }
        }

    }
    
    // Displays the results.
    for (map<char, int>::iterator itr = results.begin(); itr != results.end(); ++ itr) { cout << itr -> first << ' ' << itr -> second << '\n'; }
    
    return 0;
    
}
