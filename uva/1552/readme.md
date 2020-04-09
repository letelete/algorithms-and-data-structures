# [10611 - The Playboy Chimp](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1552&mosmsg=Submission+received+with+ID+24846953)

# My approach

### O(mlogn)

For given input, perform binary search for lower_bound and upper_bound. If lower_bound - 1 >= 0 and upper_bound exists: two values of those pointers are the answers for the task.

### Sample Input

```
4
1 4 5 7
4
4 6 8 10
```

### Sample Output

```
1 5
5 7
7 X
7 X
```
