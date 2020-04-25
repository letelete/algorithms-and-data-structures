# [11953 - Battleships](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104)

# My approach

### O(n^2)

DFS on spotted alive part of a ship. Return from recursion if next legal ceil is a dot.

# Task

Battleships game is a pen and paper game that was invented by Clifford Von Wickler in the early 1900s.
In this game each player uses two N × N grids. One to arrange his ships and record the shots of the
opponent. On the other grid the player records his own shots. Ships in battleship game can vary in
size from 1 × 1 to 1 × N/2 and can be placed both vertically and horizontally. When all of the ship’s
cells have been hit, the ship is considered sunk, otherwise it is still “alive”. Beside this, there can be
more than one ship of each size, however none of two ships can overlap or touch.
In this problem you will be given the placement of ships on the player’s grid. You will have to
calculate the number of ships that the player still owns.

---

### Input

There is a number of tests T (T ≤ 100) on the first line. Each test case contains a positive number N
(N ≤ 100) — grid size. Next N lines contain N characters each, describing the playing grid. Character
‘.’ stands for an empty cell, ‘x’ for a cell containing a ship or its part and ‘@’ for already hit part of a
ship.

---

### Output

For each test case output a single line ‘Case T: N’. Where T is the test case number (starting from 1) and N is the number of still “alive” ships.

---

### Sample Input

```
2
4
x...
..x.
@.@.
....
2
..
x.
```

---

### Sample Output

```
Case 1: 2
Case 2: 1
```
