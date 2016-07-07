#!/usr/bin/env python3

# http://www.spoj.com/problems/HUBULLU/

T = int(input())
for i in range(T):
    N, start = map(int, input().split())
    print('Airborne wins.' if start == 0 else 'Pagfloyd wins.')
