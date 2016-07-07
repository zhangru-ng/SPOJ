#!/usr/bin/env python3

# http://www.spoj.com/problems/FACEFRND/

N = int(input())
s1 = set()
s2 = set()
for i in range(N):
    f = list(map(int, input().split()))
    s1.add(f[0])
    s2 |= set(f[2:])
print(len(s2 - s1))
