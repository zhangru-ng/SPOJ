#!/usr/bin/env python3

# http://www.spoj.com/problems/BEENUMS/

from math import sqrt

N = int(input())
while N != -1:
    if (N - 1) % 3 != 0:
        print('N')
    else:
        x = (N - 1) // 3
        r = int(sqrt(x))
        print('Y' if r * (r+1) == x else 'N')
    N = int(input())


