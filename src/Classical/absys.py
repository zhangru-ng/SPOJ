#!/usr/bin/env python3

# http://www.spoj.com/problems/ABSYS/

n = int(input())
for i in range(n):
    blank = input()
    f = input().split()   
    print(f)
    if 'machula' in f[0]:
        print('{0} + {1} = {2}'.format(int(f[4]) - int(f[2]), f[2], f[4]))
    elif 'machula' in f[2]:
        print('{0} + {1} = {2}'.format(f[0], int(f[4]) - int(f[0]), f[4]))
    else:
        print('{0} + {1} = {2}'.format(f[0], f[2], int(f[2]) + int(f[0])))