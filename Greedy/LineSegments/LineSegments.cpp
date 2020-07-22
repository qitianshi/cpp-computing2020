// LineSegments.cpp
// Created on 15/7/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Finds the minimum number of line segments that can combine into a given line.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/// A horizontal line segment, represented by the x-coordinates of its start and end points.
struct HorizontalLineSegment {
    
    int startCoordinate;
    int endCoordinate;
    int length;
    
    /// Constructor for HorizontalLineSegment
    ///
    /// If `start` is greater than `end`, they are swapped as directionality is not important in this case.
    /// @param start The x-coordinate of the start of the line.
    /// @param end The x-coordinate of the end of the line.
    HorizontalLineSegment(int start, int end) {
        
        startCoordinate = start;
        endCoordinate = end;
        if (start > end) { swap(startCoordinate, endCoordinate); }
        
        length = endCoordinate - startCoordinate;
        
    }
    
    /// Checks if the given line segment `checkLine` is enveloped by this line segment.
    /// @param checkLine The line segment to be checked.
    bool envelops(HorizontalLineSegment checkLine) {
        return (this -> startCoordinate <= checkLine.startCoordinate && this -> endCoordinate >= checkLine.endCoordinate);
    }
    
};

/// A comparison function for two line segments for std::sort
///
/// `first` and `second` are first compared based on the x-coordinates of their endpoints. If they are the same, they are then compared based on their lengths. This ensures that the best line segment is placed furthest down the list, resulting in a sorted list where the last element is the best segment.
/// @param first The first line segment.
/// @param second The second line segment.
/// @return Whether `first` is to be placed before `second` when sorting.
bool compareLines(HorizontalLineSegment first, HorizontalLineSegment second) {
    if (first.endCoordinate == second.endCoordinate) { return (first.length > second.length); }
    else { return (first.endCoordinate >= second.endCoordinate); }
}

int main() {
    
    ifstream fileIn("data.txt");
    
    int targetRange;
    fileIn >> targetRange;
    
    // Stores the line segments in a vector.
    vector<HorizontalLineSegment> lineSegments;
    int leftCoordinate, rightCoordinate;
    do {
        fileIn >> leftCoordinate >> rightCoordinate;
        lineSegments.push_back({leftCoordinate, rightCoordinate});      // Pushes an instance of HorizontalLineSegment
    } while (leftCoordinate != 0 || rightCoordinate != 0);
    lineSegments.pop_back();        // Pops the last element in the vector which is (0, 0).
    
    sort(lineSegments.begin(), lineSegments.end(), compareLines);
    
    // Removes extraneous segments.
    for (vector<HorizontalLineSegment>::iterator itr = lineSegments.begin(); itr < (lineSegments.end() - 1); ++ itr) {
        
        // Removes segments if their length is zero or they exist completely outside the given range.
        if ( ((*itr).length == 0) || ( (*itr).endCoordinate < 0 || (*itr).startCoordinate > targetRange ) ) {
            lineSegments.erase(itr);
            break;
        }
        
        // Removes segments if they are enveloped by other segments.
        while ((*itr).envelops(*(itr + 1)) && itr < lineSegments.end() - 1) { lineSegments.erase(itr + 1); }
        
    }
    
    vector<HorizontalLineSegment> result;
    result.push_back({targetRange, targetRange});       // Temporarily creates a zero-length line segment so that the first element in lineSegments has something to compare to.
    while ((*(result.end() - 1)).startCoordinate > 0) {
        
        if (lineSegments[0].endCoordinate < (*(result.end() - 1)).startCoordinate) {        // There is no solution if line segments are not contiguous.
            result.clear();
            break;
        } else {
            result.push_back(lineSegments[0]);
            lineSegments.erase(lineSegments.begin());
        }
        
    }
    
    // Outputs results.
    if (result.empty()) {
        cout << "No result\n";
    } else {
        
        result.erase(result.begin());       // Removes the first (temporary) element.
        
        cout << result.size() << '\n';
        for (vector<HorizontalLineSegment>::iterator itr = result.end() - 1; itr >= result.begin(); -- itr) { cout << (*itr).startCoordinate << ' ' << (*itr).endCoordinate << '\n'; }      // Outputs line segments in order of their coordinates.
        
    }
    
    return 0;
    
}
