# Room allocator
Allocate students to rooms so that no two students from the same school are in one room.

## Description
`S` schools, numbered `1` to `S`, are sending their students to attend workshops, to be conducted in `R` rooms, numbered `1` to `R`. Allocate students so that no two students from the same school are in one room.

## Constraints
`1 ≤ S ≤ 100`, `S ∈ ℤ`

`1 ≤ R ≤ 100`, `R ∈ ℤ`

`S ≤ R`

## Input
*From `data.txt`:*
* `line 1`: the two integers `S` and `R`.
* `line 2`: `S` integers, the number of students from each school.
* `line 3`: `R` integers, the capacity of each room.

## Output (console)
*To the console:*
* `S` lines, each with the room allocations for that school in ascending order.
* Or, if there are no possible solutions, output `0`.

## Sample I/O
### Input 1
```
4 5
4 5 3 5
3 5 2 6 4
```

### Output 1
```
1 2 4 5
1 2 3 4 5
2 4 5
1 2 3 4 5
```

---

### Input 2
```
4 5
4 5 3 5
3 5 2 6 3
```

### Output 2
```
0
```

---

### Input 3
```
7 8
3 4 5 5 2 2 2
4 4 4 2 3 2 2 2
```

### Output 3
```
1 2 8
1 2 3 7
1 2 3 4 5
1 2 3 5 6
3 8
5 7
4 6
```

```
1 2 8
1 2 3 7
1 2 3 4 5
1 2 3 4 7
3 8
5 6
5 6
```

```
1 2 3
1 2 3 5
1 2 3 4 5
1 2 6 7 8
6 7
3 8
4 5
```

```
1 2 8
1 2 3 7
1 2 3 4 5
1 2 3 5 6
3 8
5 7
4 6
```

*Or any other possible combination. This list is non-exhaustive.*
