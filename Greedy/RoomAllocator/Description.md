# Room Allocator

## Description
Some schools are sending their students to attend workshops, which are to be conducted in multiple rooms. Find a way to allocate students so that no two students from the same school are in one room.

`S` is the number of schools and `R` is the number of rooms. Schools are numbered `1...S` and rooms `1...R`. `1 ≤ S ≤ 100`, `1 ≤ R ≤ 100`, and `S ≤ R`.

## Input (`data.txt`)
The first line will be two integers `S` and `R`.

The second line will be `S` integers, the number of students from each school, from `1` to `S`.

The third line will be `R` integers, the capacity of each room, from `1` to `R`.

## Output (console)
`S` lines of integers, each with the room allocations for that school in ascending order.

If there is no possible solution, output `0`.

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
