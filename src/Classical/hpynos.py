#!/usr/bin/env python3

# http://www.spoj.com/problems/HPYNOS/

T = int(input())
st = set(T)
count = 0
while T != 1:
    T = sum([int(c) ** 2 for c in str(T)])
    count += 1
    if T in st:
        count = -1
        break
    st.add(T)
print(count)
