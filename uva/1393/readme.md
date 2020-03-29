# [10452 - Marcus](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1393)

# My approach

### O(m*n*logn)

1. Assign a distinct weight to each valid letter, including start and end points.

2. Iterate through given strings' characters. On valid character spot, push it to the priority queue maintaining the actual row and column position.

3. Take first queue element as a starting point, save its position and start maintaining a current position in the grid. Depending on the value for horizontal and vertical differences of following steps, we can deduce in which direction do we need to turn.

# Task

To get to the grail, Indiana Jones needs to pass three challenges. He successfully masters the first
one and steps up to the second. A cobblestone path lies before him, each cobble is engraved with a
letter. This is the second challenge, the Word of God, the Name of God. Only the cobbles having one
of the letters “IEHOVA” engraved can be stepped on safely, the ones having a different letter will break
apart and leave a hole.
Unfortunately, he stumbles and falls into the dust, and the dust comes into his eyes, making it
impossible for him to see. So he calls for Marcus Brody and asks Marcus to tell him in which direction
to go to safely reach the other side of the cobblestone path. Because of the dust in his eyes, Indy only
can step “forth” to the stone right in front of him or do a side-step to the stone on the “left” or the
“right” side of him. These (‘forth’, ‘left’, ‘right’) are also the commands Marcus gives to him.

---

### Input

The first line of the input contains a single number indicating the number of test cases that follow.
Each test case starts with a line containing two numbers m and n (2 ≤ m, n ≤ 8), the length m
and the width n of the cobblestone path. Then follow m lines, each containing n characters (‘A’ to ‘Z’,
‘@’, ‘#’), the engravement of the respective cobblestone. Indy’s starting position is marked with the ‘@’
character in the last line, the destination with the character ‘#’ in the first line of the cobblestone path.
Each of the letters in ‘IEHOVA’ and the characters ‘@’ and ‘#’ appear exactly once in each test case.
There will always be exactly one path from Indy’s starting position via the stones with the letters
‘IEHOVA’ engraved on (in that order) to the destination. There will be no other way to safely reach the
destination.

---

### Output

For each test case, output a line with the commands Marcus gives to Indy so that Indy safely reaches
the other side. Separate two commands by one space character.

---

### Sample Input

```
2
6 5
PST#T
BTJAS
TYCVM
YEHOF
XIBKU
N@RJB
5 4
JA#X
JVBN
XOHD
DQEM
T@IY
```

---

### Sample Output

```
forth forth right right forth forth forth
right forth forth left forth forth right
```
