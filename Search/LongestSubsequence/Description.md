# Longest subsequence
Find the longest non-decreasing subsequence within a given range.

## Description
Given a sequence, `S`, of `N` rows of `M` non-decreasing integers, find the longest subsequences where the first number is greater than or equal to `L`, and the last integer is less than or equal to `H`.

## Constraints
`N ∈ ℤ`

`M ∈ ℤ`

`Sᵢ ≤ Sᵢ₊₁`, `Sᵢ ∈ ℤ`

## Input
*From `data.txt`:*
* `line 1`: the two integers `N` and `M`, separated by a space.
* `subsequent N lines`: one row of `M` space-separated numbers.
* `final line`: the two integers `L` and `H`, separated by a space.

## Output
*To the console:*
* Each subsequence, one per line, in the order that they appear.
* Or, if there are no possible subsequences, output `No Solution`.

## Sample I/O
### Input
```
6 5
2 4 4 7 9
3 4 5 6 7
1 3 5 7 8
2 4 5 5 6
1 3 3 8 9
3 4 4 5 6
4 7
```

### Output
```
4 5 6 7
4 5 5 6
4 4 5 6
```
