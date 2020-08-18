# Road network

## Description
Given `N` cities, numbered `0` to `N-1`, on a road network, find the cities that are not reachable from each city.

## Input (`data.txt`)
The first line will be an integer `N`, `(0 < N ≤ 100)`, the number of cities.

The second line will be an integer `M`, the number of routes.

Each of the following `M` lines will consist of two integers `a` and `b`, representing a one way route from city `a` to city `b`.

## Output (console)
A list of cities that are not reachable from each city.

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
