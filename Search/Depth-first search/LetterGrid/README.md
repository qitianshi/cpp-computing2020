# Letter grid
Find the largest contiguous area of letters in a grid.

## Description
Given an `m`-row by `n`-column rectangular grid of characters, find the size of the biggest contiguous area for each letter.

## Constraints
`m < 100`,  `m ∈ ℤ`

`n < 100`,  `n ∈ ℤ`

## Input
*From `data.txt`:*
* `line 1`: the two integers, `m` and `n`.
* `subsequent m lines`: one row of `n` characters in the grid.

## Output
*To the console:*
* For each letter, the size of the largest contiguous area.

## Sample I/O
### Input
```
6 10
a..bc..a.d
a.bbbc.dd.
eeebcbd..d
babaaad.df
...ffffff.
fff....bb.
```

### Output
```
a 3
b 7
c 3
d 7
e 3
f 10
```
