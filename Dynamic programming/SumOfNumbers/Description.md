# Sum of numbers
Find every combination of a set of numbers that add to a given sum.

## Description
Given an integer, `N`, and a sorted list of `M` integers, `L`, find every possible permutation of one or more integers in `L` whose sum is `N`.

## Constraints
`N ∈ ℤ`

`M ∈ ℤ`

`Lᵢ ∈ ℤ`, `L₀ = 1`

## Input
*From `data.txt`:*
* `line 1`: the integer, `M`.
* `line 2`: the list of integers, `L`, separated by spaces.
* `line 3`: the integer, `N`.

## Output
*To the console:*
* The number of possible solutions.
* Every possible permutation, one per line, in ascending order, with each number separated by a space character.

## Sample I/O
### Input
```
3
1 3 4
5
```

### Output
```
6
1 1 1 1 1
1 1 3
1 3 1
1 4
3 1 1
4 1
```
