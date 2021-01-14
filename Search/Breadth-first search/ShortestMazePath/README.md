# Shortest maze path
Find the length of the shortest path between two positions in a maze.

## Description
In a rectangular maze, of height `h` and width `w`, walls are marked by `x`, and spaces are marked by `-`. Find the length of the shortest path between the two positions marked by `*`. Each step can only be up, down, left, or right.

## Constraints
`0 ≤ h ≤ 20`, `h ∈ ℤ`

`0 ≤ w ≤ 60`, `w ∈ ℤ`

## Input
*From `data.txt`:*
* `line 1`: the two integers, `h` and `w`.
* `subsequent h lines`: one row of `w` characters, representing one line in the maze.

## Output
*To the console:*
* The length of the shortest path between the two points marked by `*`.
* Or, if there are no possible routes, output `No path`.

## Sample I/O
### Input 1
```
4 4
-*--
----
xx-x
---*
```

### Output 1
```
5
```

---

### Input 2
```
6 9
------*--
-xxxxx---
-x---x---
-x-*-x---
-----xx--
---------
```

### Output 2
```
12
```
