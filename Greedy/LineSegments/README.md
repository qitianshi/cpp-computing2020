# Line segments
Find the minimum number of line segments that can combine into a given line.

## Description
A line segment along the x-axis can be represented by 2 integers `L` and `R`, where `L` and `R` are respectively the x-coordinates of the left and right ends. 

Given a number of line segments along the x-axis, find the minimum number of line segments which can cover a bigger line `OM`.

## Constraints
`M ≥ 0`, `M ∈ ℤ`

`L ∈ ℤ`

`R ∈ ℤ`

## Input
*From `data.txt`:*
* `line 1`: the integer, `M`.
* `subsequent lines`: two integers, `L` and `R`.
* `final line`: `0 0`, representing the end of input.

## Output
*To the console:*
* The minimum number of line segments to cover `OM`.
* The x-coordinates of the left and right ends of each line segment, one per line.

## Sample I/O
### Input
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

### Output
```
4
-1 6
3 7
7 8
8 10
```
