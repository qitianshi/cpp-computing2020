# Road network
Find cities that are not connected in a road network.

## Description
There are `N` cities, numbered `0` to `N-1`, on a road network with `M` routes. For each city, find the cities that are not reachable.

## Constraints
`0 < N ≤ 100`, `N ∈ ℤ`

`M ∈ ℤ`

## Input
*From `data.txt`:*
* `line 1`: the integer, `N`.
* `line 2`: the integer `M`.
* `subsequent M lines`: two integers, representing a one way road between the two cities.

## Output
*To the console:*
* For each city, a list of unconnected cities.

## Sample I/O
### Input
```
6
7 
0 1
1 2
3 0
2 4
5 3
3 4
2 1
```

### Output
```
0: 3 5
1: 0 3 5
2: 0 3 5
3: 5
4: 0 1 2 3 5
5: 
```

*City `5` can reach every other city.*
