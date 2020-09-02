// ShortestMazePath.cpp
// Created on 1/9/20
// Running on macOS 10.15

// GNU General Public License version 3

// Finds the length of the shortest path between two points in a maze.


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>      // pair
#include <string>       // to_string
using namespace std;

enum NodeType { wall, space };

struct MazeNode {
    
    int xPosition;
    int yPosition;
    
    NodeType type;
    int distanceFromOrigin;
    bool wasVisited;
    
    MazeNode(int xPosition_, int yPosition_, NodeType type_, bool wasVisited_) {
        
        xPosition = xPosition_;
        yPosition = yPosition_;
        
        type = type_;
        distanceFromOrigin = -1;
        wasVisited = wasVisited_;
    }
    
};

int main() {
    
    ifstream fin("data.txt");
    
    int height, width;
    fin >> height >> width;
    
    vector<vector<MazeNode>> maze;
    vector<pair<int, int>> targets;
    for (int i = 0; i < height; ++ i) {
        
        vector<MazeNode> nextRow;
        for (int j = 0; j < width; ++ j) {
            
            char input;
            fin >> input;
            
            switch (input) {
                    
                // Wall
                case 'x': {
                    nextRow.push_back({j, i, wall, true});
                    break;
                }
                    
                // Space
                case '-': {
                    nextRow.push_back({j, i, space, false});
                    break;
                }
                    
                // Target
                case '*': {
                    targets.push_back({j, i});
                    nextRow.push_back({j, i, space, false});
                    break;
                }
                    
                default: { break; }
                    
            }
            
        }
        
        maze.push_back(nextRow);
        
    }
    
    #define origin maze[targets[0].second][targets[0].first]
    (origin).distanceFromOrigin = 0;
    (origin).wasVisited = true;
    
    queue<MazeNode*> unsearchedNodes;
    unsearchedNodes.push(&(origin));
    
    while (!unsearchedNodes.empty()) {
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        MazeNode* thisNode = unsearchedNodes.front();
        
        for (int i = 0; i < 4; ++ i) {
            
            #define nextY (*thisNode).yPosition + dy[i]
            #define nextX (*thisNode).xPosition + dx[i]
            if ( (nextY < 0) || (nextY > height - 1) || (nextX < 0) || (nextX > width - 1) ) { continue; }
            
            if(!(maze[nextY][nextX]).wasVisited) {
                
                (maze[nextY][nextX]).distanceFromOrigin = (*thisNode).distanceFromOrigin + 1;
                (maze[nextY][nextX]).wasVisited = true;
                
                unsearchedNodes.push(&(maze[nextY][nextX]));
                
            }
            
        }
        
        unsearchedNodes.pop();
        
    }
    
    #define result (maze[targets[1].second][targets[1].first].distanceFromOrigin)
    cout << (result == -1 ? "No path" : to_string(result)) << '\n';
    
    return 0;
    
}
