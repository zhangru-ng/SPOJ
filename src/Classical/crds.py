#!/usr/bin/env python3

# http://www.spoj.com/problems/CRDS/

T = int(input())

for i in range(T):
    N = int(input())
    s1 = (2 + 2*N) * N // 2
    s2 = N * (N-1) // 2
    print((s1 + s2) % 1000007)
