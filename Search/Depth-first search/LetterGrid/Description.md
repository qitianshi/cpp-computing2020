# Letter grid

## Description
Given a rectangular grid (`m` rows, `n` columns) of either alphabetical letters or a period character `.`, find the size of the biggest contiguous area of each letter.

## Input (`data.txt`)
The first line will be two integers, `m` and `n` (`m < 100`, `n < 100`).

The next `m` rows will be `n` characters each, giving the grid.

## Output (console)
List the letters in alphabetical order with the size of the biggest contiguous area for that letter. 

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

*City `5` can reach every other city.*
