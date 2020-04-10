# [Aggressive cows](https://www.spoj.com/problems/AGGRCOW/)

#### Approach

This solution uses the discrete binary search.

Let's denote, how can we come up with the base ranges for this task.
For C = 2, (2 <= C <= N), the maximum range K we can get is when we put them into stolls at the edges of the stolls straight line <=> K = stolls[N-1] - stolls[0]. Hence, the maximum range, let it be `hi`, equals K for C = 2.

The minimum range is when we put all the cows into one stoll <=> K = 0

The crucial observation here is that, we can actually maintain some artificial, minimal limit of gaps between each cow. Let it be G. If, for the given G, we cannot separate each cow individually, because we've exceed the range of the lastly placed stoll, it means, we need to lower our limit and repeat the validation process <=> `hi` = G

If we've successfuly separated each cow individually, we can now narrow our range by redeclaring the lowest range, let it be `lo`, to the G <=> `lo` = G.

We'll repeat the process while the difference between `hi` and `lo` is greater than 1.

---

#### Input

```
1
5 3
1
2
8
4
9
```

---

#### Output

```
3
```
