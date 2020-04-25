# [11231 - Black and white painting](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2172)

# My approach

### O(1)

Given 2D-matrix we can calculate an area from within we can construct our standard 8x8 chess-board.

For `n=8` and `m=8` we only have 1 starting point with an area of 1: `(n-7) * (m-7) = 1`

For larger fields we will start getting larger areas of possible building starts. These will contain the same or different by 1 amount of black and white tiles. We can't start from black ones, so we need to divide the area by 2.

For square areas where side length is an odd number, we will have 1 additional white tile, so to the previous formula we need to add `1` IFF `c == 1`, otherwise if we start from black tile, this additional tile cannot be counted.

# Task

You are visiting the Centre Pompidou which contains a lot of modern paintings. In particular you
notice one painting which consists solely of black and white squares, arranged in rows and columns like
in a chess board (no two adjacent squares have the same colour). By the way, the artist did not use
the tool of problem A to create the painting.
Since you are bored, you wonder how many 8 × 8 chess boards are embedded within this painting.
The bottom right corner of a chess board must always be white

---

### Input

The input contains several test cases. Each test case consists of one line with three integers n, m and
c. (8 ≤ n, m ≤ 40000), where n is the number of rows of the painting, and m is the number of columns
of the painting. c is always 0 or 1, where 0 indicates that the bottom right corner of the painting is
black, and 1 indicates that this corner is white.
The last test case is followed by a line containing three zeros.

---

### Output

For each test case, print the number of chess boards embedded within the given painting.

---

### Sample Input

```
8 8 0
8 8 1
9 9 1
40000 39999 0
0 0 0
```
