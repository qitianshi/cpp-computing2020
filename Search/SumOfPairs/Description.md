# Sum of Pairs

## Description
Given a sequence of `N` non negative integers `(N ≤ 10,000)` and another integer `M`, find all possible unique pairs of integers `X` and `Y` from the sequence such that `M = X + Y`. 

*Note: For `M=5`; the pair `X=2`, `Y=3` is considered as the same as `X=3`, `Y=2`*

## Input (`data.txt`)
The first line will be an integer `N`. 

`N` integers will follow, delimited by a space or newline character.

The last line will be an integer `M`.

### Sample
```
10
4 1 4 2 3 5 6 8 0 1 
8
```

## Output (console)
Unique pairs of the integers `X` and `Y`, one per line, in ascending order of `X`.

If there is no such pair, output `None`.

### Sample
```
0 8
2 6
3 5
4 4
```
