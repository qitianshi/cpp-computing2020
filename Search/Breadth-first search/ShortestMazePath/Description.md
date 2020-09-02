# Shortest maze path

## Description
In a rectangular maze of height `h` and width `w`, walls are marked by `x`, and spaces are marked by `-`.

Find the length of the shortest path between the two points marked by `*`. Each step can only be up, down, left, or right.

## Constraints
`0 ≤ h ≤ 20`

`0 ≤ w ≤ 60`

## Input (`data.txt`)
The first line will be two integers, `h` and `w`.

The next `h` lines will be `w` characters each, representing each point in the maze.

## Output (console)
The length of the shortest path between the two points marked by `*`.

If there is no route, output `No path`.

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
