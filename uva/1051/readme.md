# [1051 - Light, more light](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1051)

# My approach

### O(sqrt(N))

```
Count divisors of given N.
For even amount of divisors the switch will stay to be turned off, otherwise on.

We can count such amount in O(sqrt(N)) time realising that for every P, where N % P == 0, we can also get K, where K = N / P. If P != K, we increase an amount by two, else by one. We won't exceed number of sqrt(N) in interation, because all possible dividors in this area are already discovered.
```

### O(1)

````
We can reduce the time to O(1) by noticing that the amount of divisors is odd IFF the given N is a perfect square and so, can be represented as: int(sqrt(N))^2.```
````

# Task

```
There is man named ”mabu” for switching on-off light in our University. He switches on-off the lights
in a corridor. Every bulb has its own toggle switch. That is, if it is pressed then the bulb turns on.
Another press will turn it off. To save power consumption (or may be he is mad or something else)
he does a peculiar thing. If in a corridor there is n bulbs, he walks along the corridor back and forth
n times and in i-th walk he toggles only the switches whose serial is divisable by i. He does not press
any switch when coming back to his initial position. A i-th walk is defined as going down the corridor
(while doing the peculiar thing) and coming back again. Now you have to determine what is the final
condition of the last bulb. Is it on or off?
```

---

### Input

```
The input will be an integer indicating the n’th bulb in a corridor. Which is less then or equals 232 −1.
A zero indicates the end of input. You should not process this input.
```

---

### Output

```
Output ‘yes’ if the light is on otherwise ‘no’, in a single line.
```

---

### Sample Input

```
3
6241
8191
0
Sample Output
no
yes
no
```
