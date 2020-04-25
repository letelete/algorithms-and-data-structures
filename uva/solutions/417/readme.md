# [476 - Points in Figures: Rectangles](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=417)

# My approach

### O(N)

Loop through all rectangles and check for the collision.

# Task

Given a list of rectangles and a list of points in the x-y plane, determine for each point which figures
(if any) contain the point.

---

### Input

There will be n(≤ 10) rectangles descriptions, one per line. The first character will designate the type
of figure (“r” for rectangle). This character will be followed by four real values designating the x-y
coordinates of the upper left and lower right corners.
The end of the list will be signalled by a line containing an asterisk in column one.
The remaining lines will contain the x-y coordinates, one per line, of the points to be tested. The
end of this list will be indicated by a point with coordinates 9999.9 9999.9; these values should not be
included in the output.
Points coinciding with a figure border are not considered inside.

---

### Output

For each point to be tested, write a message of the form:
Point i is contained in figure j
for each figure that contains that point. If the point is not contained in any figure, write a message of
the form:
Point i is not contained in any figure
Points and figures should be numbered in the order in which they appear in the input.
Note: See the picture on the right for a diagram of these figures and data points.

---

### Sample Input

```
r 8.5 17.0 25.5 -8.5
r 0.0 10.3 5.5 0.0
r 2.5 12.5 12.5 2.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
```

### Sample Output

```
Point 1 is contained in figure 2
Point 2 is contained in figure 2
Point 2 is contained in figure 3
Point 3 is contained in figure 3
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 6 is not contained in any figure
```
