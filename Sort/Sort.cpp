// Sort.cpp
// Created on 23/6/20
// Running on macOS 10.15

// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International

// Insertion sort, selection sort, bubble sort, merge sort, quicksort, counting sort, and heap sort algorithms.


#include <iostream>
#include <stdlib.h>     // Randomizer
#include <time.h>       // Time, acts as seed for randomizer.
#include <chrono>       // High resolution chronograph to time code.
using namespace std;


/// Sorts the given array using insertion sort.
///
/// Insertion sort iterates through each element, removing one at a time starting from the one at index 1, and brings it forward to the correct position. Insertion sort has a time complexity of O(n²).
/// @param sortArray The array to be sorted.
/// @param arraySize The size of the array.
void insertionSort(int sortArray[], int arraySize) {
    for (int i = 1; i < arraySize; ++ i) {
        
        int value = sortArray[i];       // Temporarily stores the original value.
        int key = i - 1;
        
        while (key >= 0 && sortArray[key] > value) {    // Decrements the value of the key and swaps values.
            sortArray[key + 1] = sortArray[key];
            key --;
        }
        
        sortArray[key + 1] = value;     // Assigns the value to its new position.
        
    }
}

/// Sorts the given array using selection sort.
///
/// Selection sort repeatedly finds the minimum value element from the unsorted subarray and places it at the beginning of that subarray, Selection sort has a time complexity of O(n²), and generally performs worse than insertion sort.
/// @param sortArray The array to be sorted.
/// @param arraySize The size of the array.
void selectionSort(int sortArray[], int arraySize) {
    for (int i = 0; i < arraySize - 1; ++ i) {
        
        int smallestKey = i;        // Smallest key defaults to i so that the smallest value in the unsorted subarray can be found.
        
        for (int j = i + 1; j < arraySize; ++ j) {      // Finds the smallest value in the unsorted subarray.
            if (sortArray[j] < sortArray[smallestKey]) { smallestKey = j; }
        }
        
        swap(sortArray[smallestKey], sortArray[i]);
        
    }
}

/// Sorts the given array using bubble sort.
///
/// Bubble sort repeatedly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order. Bubble sort has a time complexity of O(n²).
/// @param sortArray The array to be sorted.
/// @param arraySize The size of the array.
void bubbleSort(int sortArray[], int arraySize) {
    for (int i = 0; i < arraySize - 1; ++ i) {
        for (int j = 0; j < arraySize - i - 1; ++ j) {
            if (sortArray[j] > sortArray[j + 1]) { swap(sortArray[j], sortArray[j + 1]); }      // Compares each element with its adjacent one.
        }
    }
}

/// Helper function for mergeSort().
/// @param sortArray The array to be sorted.
/// @param leftIndex The left index of the first subarray.
/// @param middleIndex The right index of the first subarray.
/// @param rightIndex The right index of the second subarray.
void merge(int sortArray[], int leftIndex, int middleIndex, int rightIndex) {
    
    int firstSubarraySize = middleIndex - leftIndex + 1;
    int secondSubarraySize = rightIndex - middleIndex;
    
    // Creates temporary arrays to store elements from the main list.
    int firstSubarray[firstSubarraySize];
    int secondSubarray[secondSubarraySize];
    for (int i = 0; i < firstSubarraySize; ++ i) { firstSubarray[i] = sortArray[leftIndex + i]; }
    for (int i = 0; i < secondSubarraySize; ++ i) { secondSubarray[i] = sortArray[middleIndex + 1 + i]; }
    
    int firstSubarrayIndex = 0;         // Initial index of first subarray
    int secondSubarrayIndex = 0;        // Initial index of second subarray
    int mergedArrayIndex = leftIndex;   // Initial index of merged array
    
    // Merges the temporary arrays back into the main array.
    while (firstSubarrayIndex < firstSubarraySize && secondSubarrayIndex < secondSubarraySize) {
        
        if (firstSubarray[firstSubarrayIndex] <= secondSubarray[secondSubarrayIndex]) {
            sortArray[mergedArrayIndex] = firstSubarray[firstSubarrayIndex];
            firstSubarrayIndex ++;
        } else {
            sortArray[mergedArrayIndex] = secondSubarray[secondSubarrayIndex];
            secondSubarrayIndex ++;
        }
        
        mergedArrayIndex ++;
        
    }
    
    // Copies over the remaining elements in firstSubarray
    while (firstSubarrayIndex < firstSubarraySize) {
        sortArray[mergedArrayIndex] = firstSubarray[firstSubarrayIndex];
        firstSubarrayIndex ++;
        mergedArrayIndex ++;
    }
    
    // Copies over the remaining elements in secondSubarray
    while (secondSubarrayIndex < secondSubarraySize) {
        sortArray[mergedArrayIndex] = secondSubarray[secondSubarrayIndex];
        secondSubarrayIndex ++;
        mergedArrayIndex ++;
    }
    
}

/// Sorts the given array using merge sort.
///
/// Merge sort is a divide and conquer algorithm. It divides the array in two halves, calls itself for the two halves and then merges the two sorted halves. Merge sort has a time complexity of O(n log n), and is efficient with large lists.
/// @param sortArray The array to be sorted.
/// @param leftIndex The left index of the subarray.
/// @param rightIndex The right index of the subarray.
void mergeSort(int sortArray[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {       // leftIndex > rightIndex indicates that the subarray has been split into individual elements; comparison returns false and the function returns.
    
        int middleIndex = (leftIndex + rightIndex) / 2;     // Casting to int allows this to work for odd-numbered arrays as well.
        
        mergeSort(sortArray, leftIndex, middleIndex);       // Sorts the left subarray.
        mergeSort(sortArray, middleIndex + 1, rightIndex);  // Sorts the right subarray.
        
        merge(sortArray, leftIndex, middleIndex, rightIndex);
        
    }
}

/// Sorts the given array using quicksort.
///
/// Quicksort is a divide and conquer algorithm. This implementation picks the last element as pivot and partitions the given array around the picked pivot, such that elements to the left are smaller and elements to the right are greater. Merge sort has a time complexity of O(n log n).
/// @param sortArray The array to be sorted.
/// @param leftIndex The left index of the subarray.
/// @param rightIndex The right index of the subarray.
void quickSort(int sortArray[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {       // leftIndex > rightIndex indicates that the subarray has been split into individual elements; comparison returns true and the function returns.
        
        int smallerElementIndex = leftIndex - 1;    // Initializes with a default value.
        
        for (int j = leftIndex; j < rightIndex; ++ j) {
            if (sortArray[j] < sortArray[rightIndex]) {     // The last element in the subarray is used as the pivot.
                smallerElementIndex ++;
                swap(sortArray[smallerElementIndex], sortArray[j]);
            }
        }
        
        swap(sortArray[smallerElementIndex + 1], sortArray[rightIndex]);
        
        int partitionIndex = smallerElementIndex + 1;
        
        quickSort(sortArray, leftIndex, partitionIndex - 1);        // Sorts the left subarray.
        quickSort(sortArray, partitionIndex + 1, rightIndex);       // Sorts the right subarray.
        
    }
}

/// Sorts the given array using counting sort.
///
/// Counting sort counts the number of occurences of unique elements. This implementation of counting sort only works when the range of elements is known, and when the list consists entirely of positive integers. Counting sort has a time complexity of O(n + k), where k is the range of key values.
/// @param sortArray The array to be sorted.
/// @param arraySize The size of the array.
void countingSort(int sortArray[], int arraySize) {
    
    // Finds the maximum value in the array.
    int maxValue = INT_MIN;
    for (int i = 0; i < arraySize; ++ i) {
        if (sortArray[i] > maxValue) { maxValue = sortArray[i]; }
    }
    
    // Creates a temporary array to store occurences of each element.
    int output[maxValue + 1];
    for (int i = 0; i < maxValue + 1; ++ i) { output[i] = 0; }      // Variable-sized arrays cannot be directly initialized.

    // Records the number of occurences of each element.
    for (int i = 0; i < arraySize; ++ i) { output[sortArray[i]] ++; }

    // Modifies the original array.
    int sortArrayIndex = 0;
    for (int i = 0; i < maxValue + 1; ++ i) {
        for (int j = 0; j < output[i]; ++ j) {
            sortArray[sortArrayIndex] = i;
            sortArrayIndex ++;
        }
    }
    
}

/// Helper function for heapSort().
/// @param sortArray The array to be sorted.
/// @param upperIndex The upper index.
/// @param lowerIndex The lower index.
void heapify(int sortArray[], int upperIndex, int lowerIndex) {
    
    // Find the largest among root, left child and right child
    int largestElementIndex = lowerIndex;
    int leftChild = 2 * lowerIndex + 1;
    int rightChild = 2 * lowerIndex + 2;

    // Reassigns the index of the largest element
    if (leftChild < upperIndex && sortArray[leftChild] > sortArray[largestElementIndex]) { largestElementIndex = leftChild; }
    if (rightChild < upperIndex && sortArray[rightChild] > sortArray[largestElementIndex]) { largestElementIndex = rightChild; }

    // Swap and continue heapifying if the root is not largest.
    if (largestElementIndex != lowerIndex) {
      swap(sortArray[lowerIndex], sortArray[largestElementIndex]);
      heapify(sortArray, upperIndex, largestElementIndex);
    }
    
}

/// Sorts the given array using heap sort.
///
/// Heap sort divides the array into a sorted and an unsorted region, and iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. Heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step, unlike the similar selection sort which performs a linear-time scan of the unsorted region. Heap sort has a time complexity of O(n log n).
/// @param sortArray The array to be sorted.
/// @param arraySize The size of the array.
void heapSort(int sortArray[], int arraySize) {
    
    // Builds a max-heap
    for (int i = arraySize / 2 - 1; i >= 0; -- i) { heapify(sortArray, arraySize, i); }

    for (int i = arraySize - 1; i >= 0; -- i) {
      swap(sortArray[0], sortArray[i]);
      heapify(sortArray, i, 0);     // Heapifies the root element after each iteration to move largest element back to the root.
    }
    
}

int main() {
    
    int arraySize, sortMethod;
    
    while (true) {
        
        cout << "----------\n";
        
        cout << "Number of elements: ";
        cin >> arraySize;
        if (arraySize == 0) { break; }
        
        cout << "Sort method: ";
        cin >> sortMethod;
        
        int *sortArray = new int[arraySize];        // Declares a pointer to a dynamically allocated array, instead of declaring the array itself. This is necessary because arraySize is not known at buildtime, so the code crashes if the array is too large.
        
        // Generates a random sequence of numbers for the array.
        srand(static_cast<unsigned int>(time(NULL)));       // Casts time(), type long, to unsigned int.
        for (int i = 0; i < arraySize; ++ i) { sortArray[i] = rand() % 101; }
        
        // Prints the original array.
        if (arraySize <= 100) {
            cout << "\nUnsorted array\n";
            for (int i = 0; i < arraySize; ++ i) { cout << sortArray[i] << ' '; }
            cout << '\n';
        }
        
        string sortType;
        auto start = chrono::steady_clock::now();
        
        switch (sortMethod) {        // Times each sort method and displays the time required in microseconds.
                
            // Insertion sort
            case 1: {
                insertionSort(sortArray, arraySize);
                sortType = "Insertion sort";
                break;
            }
                
            // Selection sort
            case 2: {
                selectionSort(sortArray, arraySize);
                sortType = "Selection sort";
                break;
            }
                
            // Bubble sort
            case 3: {
                bubbleSort(sortArray, arraySize);
                sortType = "Bubble sort";
                break;
            }
                
            // Merge sort
            case 4: {
                mergeSort(sortArray, 0, arraySize - 1);
                sortType = "Merge sort";
                break;
            }
            
            // Quicksort
            case 5: {
                quickSort(sortArray, 0, arraySize - 1);
                sortType = "Quicksort";
                break;
            }
            
            // Counting sort
            case 6: {
                countingSort(sortArray, arraySize);
                sortType = "Counting sort";
                break;
            }
            
            // Heap sort
            case 7: {
                heapSort(sortArray, arraySize);
                sortType = "Heap sort";
                break;
            }
                
            default: {
                cout << "\nInvalid selection.\n";
                break;
            }
                
        }
        
        auto end = chrono::steady_clock::now();
        
        // Checks that the selected sort method is valid.
        if (sortType != "") {
        
            cout << "\n" << sortType;
            
            // Prints the sorted array.
            if (arraySize <= 100) {
                cout << '\n';
                for (int i = 0; i < arraySize; ++ i) { cout << sortArray[i] << ' '; }
            }
            
            cout << "\nCompleted in " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs.\n";
            
        }
        
        sortType = "";
        
        cout << '\n';
        
    }
    
    return 0;
    
}

