# Sorting algorithms
**Contents**
* [Counting sort](#counting-sort)
* [Insertion sort](#insertion-sort)
* [Selection sort](#selection-sort)
* [Bubble sort](#bubble-sort)
* [Merge sort](#merge-sort)
* [Quicksort](#quicksort)
* [Heap sort](#heap-sort)

## Counting sort
Counting sort counts the number of occurrences of unique elements.

```C++
void countingSort(int sortArray[], int arraySize) {
    
    // Finds the maximum value in the array.
    int maxValue = INT_MIN;
    for (int i = 0; i < arraySize; ++ i) {
        if (sortArray[i] > maxValue) { maxValue = sortArray[i]; }
    }
    
    // Creates a temporary array to store occurences of each element.
    int output[maxValue + 1];
    // Variable-sized arrays cannot be directly initialized.
    for (int i = 0; i < maxValue + 1; ++ i) { output[i] = 0; }     

    // Records the number of occurrences of each element.
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
```

This implementation finds the maximum element in the array, then creates an array to store the number of occurrences of each element, where the index represents the element and its value represents the corresponding number of occurrences. The original array is then overwritten.

This implementation can be vastly improved because it only works when the list consists entirely of positive integers, and wastes a huge amount of memory and time when there is a single very large element. A better implementation would be to use a map to store the number of occurrences for each element.

Counting sort has a time complexity of O(n + k), where k is the range of key values.

## Insertion sort
Iterates through each element, taking one at a time starting from the one at index 1, and brings it forward to the correct position. The array therefore has a sorted (front) subarray, and an unsorted (back) subarray.

```C++
void insertionSort(int sortArray[], int arraySize) {
    for (int i = 1; i < arraySize; ++ i) {
        
        int value = sortArray[i];       // Temporarily stores the original value.
        int key = i - 1;
        
        // Decrements the value of the key and swaps values.
        while (key >= 0 && sortArray[key] > value) {
            sortArray[key + 1] = sortArray[key];
            key --;
        }
        
        sortArray[key + 1] = value;     // Assigns the value to its new position.
        
    }
}
```

The main `for` loop only begins with the element at index 1 because the first element is the basis on which the sorted subarray will be built at the front of the array.

The `while` loop moves every single element to the next spot while searching for the correct new position for the current `value`. When the loop ends, every value in the sorted subarray that is to be moved has been moved, with the exception of the destination index which retains its original value; the second-last line writes in the new value to the destination index.

Because insertion sort attempts to place the first element of the unsorted subarray into its correct position in the sorted subarray, key begins with `i-1`.

Insertion sort has a time complexity of O(n²).

## Selection sort
Selection sort repeatedly finds the minimum value element from the unsorted subarray and places it at the beginning of that subarray.

```C++
void selectionSort(int sortArray[], int arraySize) {
    for (int i = 0; i < arraySize - 1; ++ i) {

        // Smallest key defaults to i so that the smallest value in the unsorted subarray 
           can be found.
        int smallestKey = i;

        // Finds the smallest value in the unsorted subarray.
        for (int j = i + 1; j < arraySize; ++ j) {     
            if (sortArray[j] < sortArray[smallestKey]) { smallestKey = j; }
        }
        
        swap(sortArray[smallestKey], sortArray[i]);
        
    }
}
```

The outer `for` loop ends with the second-to-last element because by the time there is only one element left in the unsorted subarray, it has to be the maximum value, and since it’s already at the end of the array, it’s already sorted.

The inner `for` loop begins with `i+1` because `smallestKey` is already set to `i`; to find the smallest element in the unsorted subarray, the basis of comparison begins with the first element.

The smallest element in the unsorted subarray is the next element in the sorted subarray, thus it’s brought to the front of the unsorted subarray, which is also the end of the sorted subarray.

Selection sort has a time complexity of O(n²), but generally performs worse than insertion sort.

## Bubble sort
Bubble sort repeatedly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order.

```C++
void bubbleSort(int sortArray[], int arraySize) {
    for (int i = 0; i < arraySize - 1; ++ i) {
        for (int j = 0; j < arraySize - i - 1; ++ j) {
            // Compares each element with its adjacent one.
            if (sortArray[j] > sortArray[j + 1]) { swap(sortArray[j], sortArray[j + 1]); }
        }
    }
}
```

The outer `for` loop ends with the second-to-last element because the algorithm needs to run once for every element in the array, with the exception of the final element, which is the smallest element and is guaranteed to be at the front of the array when the algorithm is complete.

The inner `for` loop ends with `arraySize - i - 1` because with every pass of the algorithm, the sorted subarray at the end grows by 1, as the largest element in the unsorted subarray is added to the front of the sorted subarray. It’s **`- 1`** because the `if` comparison compares `sortedArray[j]` with `sortedArray[j + 1]`.

Bubble sort has a time complexity of O(n²).

## Merge sort
Merge sort is a divide and conquer algorithm. It divides the array in two halves, calls itself for the two halves and then merges the two sorted halves.

```C++
void mergeSort(int sortArray[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {       // leftIndex > rightIndex indicates that the subarray has been split into individual elements; comparison returns false and the function returns.
        
        int middleIndex = (leftIndex + rightIndex) / 2;     // Casting to int allows this to work for odd-numbered arrays as well.
        
        mergeSort(sortArray, leftIndex, middleIndex);       // Sorts the left subarray.
        mergeSort(sortArray, middleIndex + 1, rightIndex);  // Sorts the right subarray.
        
        merge(sortArray, leftIndex, middleIndex, rightIndex);
        
    }
}
```

Merge sort is a recursive algorithm with a main function, `mergeSort()`, that divides the array into subarrays until individual elements are obtained, and a secondary function, `merge()`, that combines adjacent subarrays into a single, sorted array.

In `mergeSort()`, the `if` statement determines if the subarray has already been split into individual components. If the algorithm reaches a point where `leftIndex` is smaller than or equal to `rightIndex`, that means it’s requesting a split that cannot exist, because it’s attempting to split a single element. Thus, the function returns.

When the last left-splitting function in the call stack returns (indicating that it has split all left subarrays into individual elements), the algorithm moves on to the next line, where it performs `mergeSort()` on the right array. Because we are currently at the deepest point in the first branch, there is only one element to the right of the left element, hence the `mergeSort()` for the right branch returns immediately. It then merges the left and right elements together using `merge()`. We then move one level up the call stack, and the process can repeat with the right subarray. This algorithm repeats until the entire array is sorted.

It’s important to note that merge sort does not split the entire array into individual elements first and merge them all at once; instead it’s a bottom-up algorithm that goes all the way down into the left-most branch, sorts it, then moves onto the next adjacent branch, sorts that branch, and then merges the first and second branches together, before moving on to with the next group of branches.

Once split, the algorithm then merges the left and right subarrays by calling a helper function, `merge()`.

```C++
void merge(int sortArray[], int leftIndex, int middleIndex, int rightIndex) {
    
    // Creates temporary arrays to store elements from the main list.
    queue<int> leftArray;
    queue<int> rightArray;
    for (int i = leftIndex; i <= middleIndex; ++ i) { leftArray.push(sortArray[i]); }
    for (int i = middleIndex + 1; i <= rightIndex; ++ i) { rightArray.push(sortArray[i]); }
    
    // Merges the two subarrays back into the main array.
    int marker = leftIndex;     // The position of the next insertion.
    while (!leftArray.empty() && !rightArray.empty()) {
        
        if (leftArray.front() < rightArray.front()) {
            sortArray[marker] = leftArray.front();
            leftArray.pop();
        } else {
            sortArray[marker] = rightArray.front();
            rightArray.pop();
        }
        
        marker ++;
        
    }
    
    // Copies over remaining elements, if there are any.
    while (!leftArray.empty()) {
        sortArray[marker] = leftArray.front();
        leftArray.pop();
        marker ++;
    }
    while (!rightArray.empty()) {
        sortArray[marker] = rightArray.front();
        rightArray.pop();
        marker ++;
    }
    
}
```

`secondSubarraySize` is defined as a simplified version of the actual calculation: `rightIndex - (middleIndex + 1) + 1`. 

The algorithm then copies the contents of the left and right subarrays to be merged. In this implementation, the original array is directly overwritten with the new values instead of swapping or reorganizing values.

`mergedArrayIndex` indicates the position in the main array to which new elements will be added.

The first `while` loop is the only part where comparison between the left and right subarrays takes place. The algorithm chooses the smaller of the values from the front of either subarray and places it into the main array by overwriting the existing value (which is why the left and right subarrays first need to be copied into a temporary array). This loop ends when either the left or right subarray has been completely inserted into the main array.

Only one of the final two `while` loops will be run. Because the first `while` loop ends immediately when either one subarray has been inserted, it’s likely that the other subarray has still not been depleted. Thus, depending on which one it is, one of the final two `while` loops will fill in the remainder. Because the remaining elements guaranteed to both be in order and also be greater than the last element inserted by the first `while` loop, it’s unnecessary to do any more sorting and the remaining elements can be directly inserted.

Merge sort has a time complexity of O(n log n), and is efficient with large lists.

## Quicksort
Quicksort is a divide and conquer algorithm. This implementation picks the last element as pivot and partitions the given array around the selected pivot, such that elements to the left are smaller and elements to the right are greater.

```C++
void quickSort(int sortArray[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        
        int smallerElementIndex = leftIndex - 1;    // Initializes with a default value.
        
        for (int j = leftIndex; j < rightIndex; ++ j) {
            // The last element in the subarray is used as the pivot.
            if (sortArray[j] < sortArray[rightIndex]) {    
                smallerElementIndex ++;
                swap(sortArray[smallerElementIndex], sortArray[j]);
            }
        }
        
        swap(sortArray[smallerElementIndex + 1], sortArray[rightIndex]);
        
        int partitionIndex = smallerElementIndex + 1;
        
        quickSort(sortArray, leftIndex, partitionIndex - 1);  // Sorts the left subarray.
        quickSort(sortArray, partitionIndex + 1, rightIndex); // Sorts the right subarray.
        
    }
}
```

Quicksort splits each subarray into two: the less-than (left) partition and the greater-than (right) partition. It’s a top-down approach that continues splitting until all elements are sorted. While this implementation uses the last element as the pivot, it’s possible to use any element in the subarray.

`smallerElementIndex` is a store of the index of the last element of the less-than partition. It’s tedious and inefficient to actually place the pivot between the two partitions, since every time something is added to the less-than partition, the partition element would need to be moved one step to the right. Instead, the partition element is simply swapped into place at the very end.

Notice that nowhere in this algorithm do we compare each element with anything other than the pivot. It doesn’t matter the order of each element within their respective partitions, as long as all the elements are in the correct partitions. It’s for this reason that we can simply swap the pivot with the beginning of the larger-than partition, without needing to move every larger-than partition element one step to the right.

After the swap, each of the partitions are then sorted with their own pivots. The partition element itself no longer needs does not need to be included in either sort since it’s already at the correct position.

Quicksort has a time complexity of O(n log n).

## Heap sort
Heap sort divides the array into a sorted and an unsorted region, and iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. While selection sort also follows this principle, heap sort maintains the unsorted region in a heaped structure to quickly find the largest element.

```C++
void heapSort(int sortArray[], int arraySize) {
    
    // Builds a max-heap
    for (int i = arraySize / 2 - 1; i >= 0; -- i) { heapify(sortArray, i, arraySize - 1); }
    
    for (int i = arraySize - 1; i > 0; -- i) {
        swap(sortArray[0], sortArray[i]);
        heapify(sortArray, 0, i);     // Heapifies the root element after each iteration to move largest element back to the root.
    }
    
}
```

Heap sort represents the data as a max-heap, a special type of binary tree where each node is greater than or equal to its children. This algorithm never creates an actual structure or class of binary tree, instead the tree is represented by array indexes: it starts from zero at the root, then increases increments horizontally for each subsequent level. This structure allows each of the children of a node to be found easily: for the element at index `i`, its children are `2i+1` and `2i+2`. Conversely, the parent of any node `i` is the lower bound of `(i-1)/2`.

`heapify()` will heapify the nodes from the bottom up, taking the first element as the parent and heapifying its two children (because the root is at index 0, bottom means the largest unsorted element). Thus, to fully heapify the original array, we must begin with the last non-leaf (or parent) node that has children, which is at `arraySize / 2 - 1` (all subsequent nodes do not have any children) thus this is where the first `for` loop, which is to build a complete max-heap, begins.

Once the heapification is complete, sorting can begin. The second `for` loop begins with `arraySize - 1` because it’s the last element in the array, so that’s where the largest element will be placed to begin the sorted subarray at the rear. Every time a new element is added to the sorted subarray, the next position to be filled decreases by one.

Once the root (largest element) has been moved to the correct position at the end of the array, the smallest element is now at the root of the heap, because the first (largest) element was swapped with the last (smallest) element. Thus, it runs `heapSort()` again to restore the max-heap. Since this time most of the heap already exists, and we’re confident that there is an unbroken path from the root all the way to the end, we can call `heapify()` beginning with the first element: `heapify(sortArray, 0, i)`.

```C++
void heapify(int sortArray[], int rootIndex, int maximumIndex) {
    
    // Finds the largest among root, left child and right child.
    int largestElementIndex = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;
    
    // Reassigns the index of the largest element
    if (leftChild < maximumIndex && sortArray[leftChild] > sortArray[largestElementIndex]) { largestElementIndex = leftChild; }
    if (rightChild < maximumIndex && sortArray[rightChild] > sortArray[largestElementIndex]) { largestElementIndex = rightChild; }
    
    // Swaps and continues heapifying if the root is not largest.
    if (largestElementIndex != rootIndex) {
        swap(sortArray[rootIndex], sortArray[largestElementIndex]);
        heapify(sortArray, largestElementIndex, maximumIndex);
    }
    
}
```

The `heapify()` function begins by identifying the root (the first index in the subarray) as the largest item. It doesn’t matter that the first element isn’t actually the largest since the algorithm will run checks later to create the max-heap. The indexes of the children of the largest element are also stored.

The algorithm then checks if the node and its two children follow the rules of a max-heap. If not, they are swapped to ensure that the parent is greater than or equal to both its children. This is also where the index of the left and right children are checked to make sure that they are within range of the subarray. Thus, these three elements have been heapified.

The `maximumIndex` parameter exists to tell `heapify()` when it’s reached the last group of nodes, which it can tell from when the children are outside the requested range.

The final `if` statement checks if there has been any change to where the largest element was. If so, it’s possible that the remainder of the heap needs to be reheapified as well, and `heapify()` calls itself to heapify each of the child branches.

Heap sort has a time complexity of O(n log n).

---

This document shall be licensed under the [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0) license](https://creativecommons.org/licenses/by-nc-sa/4.0/).
