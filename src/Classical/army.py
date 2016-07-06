#!/usr/bin/env python3

# http://www.spoj.com/problems/ARMY/

T = int(input())

for i in range(T):
    blank = input()
    Ns = input()
    a = map(int, input().split())
    b = map(int, input().split())
    if max(a) >= max(b):
        print("Godzilla")
    else:
        print("MechaGodzilla")
