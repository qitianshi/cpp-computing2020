// RoomAllocator.cpp
// Created on 29/7/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Allocates students to rooms so that no two students from the same school are in one room.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>        // sort
using namespace std;

/// A school, represented by its number and the number of students they send.
struct School {
    int number;
    int students;
    vector<int> rooms;
};

/// A room, represented by its number and its capacity.
struct Room {
    int number;
    int capacity;
};

/// A comparison function for sorting rooms by their capacity, in descending order.
bool compareRoomsByCapacity(Room first, Room second) { return (first.capacity > second.capacity); }

/// A comparison function for sorting schools by their number of students, in descending order.
bool compareSchoolsByStudents(School first, School second) { return (first.students > second.students); }

/// A comparison function for sorting schools by their number, in ascending order.
bool compareSchoolsByNumber(School first, School second) { return (first.number < second.number); }

int main() {

    ifstream fin("data.txt");
    
    int numberOfSchools, numberOfRooms;
    fin >> numberOfSchools >> numberOfRooms;
    
    // Pushes schools into a vector.
    vector<School> schools;
    for (int i = 0; i < numberOfSchools; ++ i) {
        
        int numberOfStudents;
        fin >> numberOfStudents;
        
        schools.push_back({i + 1, numberOfStudents});       // Schools are numbered from 1.
        
    }
    sort(schools.begin(), schools.end(), compareSchoolsByStudents);     // Sorts schools by their number of students, so that bigger schools are given a higher priority when allocating rooms.
    
    // Pushes rooms into a vector.
    vector<Room> rooms;
    for (int i = 0; i < numberOfRooms; ++ i) {
        
        int capacity;
        fin >> capacity;
        
        rooms.push_back({i + 1, capacity});                 // Rooms are numbered from 1.
        
    }
    sort(rooms.begin(), rooms.end(), compareRoomsByCapacity);           // Sorts rooms by their capacity, so that bigger rooms are used first.
    
    // If there are more students than rooms, there is no solution.
    if (schools[0].students > rooms.size()) {
        cout << 0 << '\n';
        return 0;
    }
    
    // Allocates rooms by placing the biggest schools into the biggest rooms first.
    for (vector<School>::iterator itrSchool = schools.begin(); itrSchool < schools.end(); ++ itrSchool) {
        
        sort(rooms.begin(), rooms.end(), compareRoomsByCapacity);       // Sorts rooms to keep the biggest room at the front of the list.
        int thisRoom = 0;
        while ( (thisRoom < rooms.size()) && ((*itrSchool).students > 0) ) {
            
            // Skips the room if it's full.
            if (rooms[thisRoom].capacity == 0) {
                thisRoom ++;
                continue;
            }
            
            (*itrSchool).rooms.push_back(rooms[thisRoom].number);       // Allocates the room.
            (*itrSchool).students --;                                   // Updates the number of remaining unallocated students.
            rooms[thisRoom].capacity --;                                // Updates the remaining capacity of the room.
            
            thisRoom ++;
            
        }
        
        // If the end of the room list is reached and there are still unallocated students, there is no solution.
        if ((*itrSchool).students > 0) {
            cout << 0 << '\n';
            return 0;
        }
        
        sort((*itrSchool).rooms.begin(), (*itrSchool).rooms.end());     // Sorts the allocations list in by the rooms' numbers.
        
    }
    
    sort(schools.begin(), schools.end(), compareSchoolsByNumber);       // Sorts the schools list by their numbers.
    for (vector<School>::iterator itrSchool = schools.begin(); itrSchool < schools.end(); ++ itrSchool) {
        for (vector<int>::iterator itr = (*itrSchool).rooms.begin(); itr < (*itrSchool).rooms.end(); ++ itr) { cout << *itr << ' '; }
        cout << '\n';
    }

    return 0;

}
