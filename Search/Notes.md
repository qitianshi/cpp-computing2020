# Searching algorithms
**Contents**
* [Binary search](#binary-search)

## Binary search

Binary search first sorts the list, then recursively compares the target with the middle element, and eliminates half the list where the target isn’t, until it finds the target or it is left with a single element that is not the target (hence the target is not found).

```C++
int binarySearch(vector<pair<int, int>> searchElements, int target, int leftIndex, int
 rightIndex) {
    
    if (rightIndex >= leftIndex) {
        
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        if (searchElements[middleIndex].first == target)
            return searchElements[middleIndex].second;     // Target has been found.
        
        // Target is in the left subarray.
        else if (searchElements[middleIndex].first > target) 
            return binarySearch(searchElements, target, leftIndex, middleIndex - 1);
        
        // Target is in the right subarray.
        else
            return binarySearch(searchElements, target, middleIndex + 1, rightIndex);      
        
    }
    
    return -1;      // When the target isn’t found.
    
}
```

Similar to the checks in divide-and-conquer sorting algorithms such quicksort and merge sort, the first `if` statement checks that the subarray can still be further broken down. If this algorithm reaches a fully broken-down state and the target still is not found, the `if` statement is completed and the function is allowed to reach the `return -1`; line, hence the element does not exist. However, unlike those algorithms, the comparator used is `>=` instead of `>`, because we must allow single elements to run through the algorithm to be able to find the one element that is the target.

`middleIndex` is taken as the middle point between `leftIndex` and `rightIndex`. If the target element happens to be at this index, it is found and the function returns, bringing the result all the way back through the call stack. If not, the algorithm calls the `binarySearch()` function again, and the parameters passed in are dependent on which side of `middleIndex` the target is in (hence the original array must be pre-sorted). `middleIndex` itself does not need to be included in either side because we already know it’s not the correct value.

Binary search has a time complexity of O(log n).
