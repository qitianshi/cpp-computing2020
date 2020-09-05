# Sum of pairs
Find unique pairs of integers that add to a given number.

## Description
Given a number, `M`, and a list, `L`, of `N` non-negative integers, find every unique pair in the list whose sum is `M`. 

`1+2` is the same as `2+1`.

## Constraints
`N ≤ 10 000`, `N ∈ ℤ`

`Lᵢ ≥ 0`, `Lᵢ ∈ ℤ`

## Input
*From `data.txt`:*
* `line 1`: the integer, `N`.
* `line 2`: the list of space-separated integers, `L`.
* `line 3`: the number, `M`.

## Output
*To the console:*
* Each unique pair of integers, smaller first, one pair per line, in ascending order.
* Or, if there are no possible combinations, output `None`.

## Sample I/O
### Input
```
10
4 1 4 2 3 5 6 8 0 1 
8
```

### Output
```
0 8
2 6
3 5
4 4
```
