# Island hopper
Find the shortest path between connected islands.

## Description
There are `N` islands, numbered `1` to `N`, some of which are connected by `M` bidirectional bridges. Using the optimal route, find the minimum number of bridges that must be crossed to travel from one island, `x`, to another, `y`.

## Constraints
`N ≥ 1`, `N ∈ ℤ`

`M ≤ 1000`, `M ∈ ℤ`

`x ≥ 1`, `x ∈ ℤ`

`y ≤ 1000`, `y ∈ ℤ`

`x ≠ y`

## Input
*From `data.txt`:*
* `line 1`: the two integers, `N` and `M`.
* `subsequent m lines`: two integers, representing a two-way bridge between the two islands.
* `final line`: the two integers, `x` and `y`.

## Output
*To the console:*
* An integer, the minimum number of bridges that need to crossed.

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
