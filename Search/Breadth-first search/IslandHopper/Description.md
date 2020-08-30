# Island hopper

## Description
There are `N` islands, numbered `1` to `N`, some of which are connected by `M` bidirectional bridges. Using the optimal route, find the minimum number of bridges that must be crossed to travel from one island, `X`, to another, `Y`.

## Constraints
`N ≥ 1`

`M ≤ 1000`

`1 ≤ x, y, ≤ 1000` 

`x ≠ y`

## Input (`data.txt`)
The first line will be two integers, `N` and `M`.

`M` lines will follow, each with two integral island numbers that are connected by a bridge.

The last line will be two integers, `X` and `Y`.

## Output (console)
An integer, the minimum number of bridges that need to crossed.

## Sample I/O
### Input
```
8 9
1 2
3 1
3 6
2 6
2 3
4 5
5 6
4 6
7 8
1 6
```

### Output
```
2
```
