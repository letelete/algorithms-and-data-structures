import random

MAXN = 100000
nums = list(map(lambda x: str(x), list(range(1, random.randint(1, MAXN)))))
random.shuffle(nums)
tests = MAXN

print(MAXN)
arr = " ".join(nums)
print(arr)
print(tests)
for i in range(tests):
    print(random.randint(1, MAXN))
