# Minimum coins
Finds the minimum number of coins that add to a given total.

## Description
Given `M` coins of varying denominations, which are given in a list `L`, find the combination with the smallest possible number of coins that add to a given total, `N`.

## Constraints
`0 < M < 100`, `M ∈ ℤ`

`0 < N < 100`, `N ∈ ℤ`

`Lᵢ < Lᵢ₊₁`

## Input
*From `data.txt`:*
* `line 1`: the integer, `M`, and the integer `N`.
* `line 2`: the list of integers, `L`, separated by a space.

## Output
*To the console:*
* An integer, the minimum possible number of coins.

## Sample I/O
### Input
```
4 11
1 5 6 9
```

### Output
```
2
```
