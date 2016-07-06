#!/usr/bin/env python3

# http://www.spoj.com/problems/OFFSIDE/

while True:
    A, D = map(int, input().split())
    if A == 0 and D == 0:
        break
    a1 = min(map(int, input().split()))
    d2 = sorted(map(int, input().split()))[1]
    if a1 < d2:
        print('Y')
    else:
        print('N')
