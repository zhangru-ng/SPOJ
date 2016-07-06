#!/usr/bin/env python3

# http://www.spoj.com/problems/MAXLN/

T = int(input())
for i in range(1, T+1):
    r = int(input())
    print('Case {0}: {1:.2f}'.format(i, 4 * r ** 2 + 0.25))
