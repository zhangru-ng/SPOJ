#!/usr/bin/env python3

# http://www.spoj.com/problems/ROOTCIPH/

T = int(input())
for i in range(T):
    a, b, c = map(int(input().split()))
    print(a * a - 2 * b)
