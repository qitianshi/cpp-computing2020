# Line segments

## Description
A line segment along the x-axis can be presented by 2 integers `L` and `R`, where `L` and `R` are respectively the x-coordinates of the left and right ends. 

Given a number of line segments along the x-axis, find the minimum number of line segments which can cover `OM`.

## Input (`data.txt`)
The first line will be a positive integer `M`.

The following lines will contain two integers each, `L` and `R`.

The final line is `0 0`, representing the end of input.

### Sample
```
10
-2 5
-1 6
-1 3
0 4
1 5
2 6
3 7
7 8
8 10
8 9
0 0
```

## Output (console)
The minimum number of line segments to cover `OM`, followed by the coordinates of each line segment, one per line.

### Sample
```
4
-1 6
3 7
7 8
8 10
```
