#!/usr/bin/env python3

# http://www.spoj.com/problems/FAVDICE/

T = int(input())
for i in range(T):
	N = int(input())
	print(N * sum([1/x for x in range(1, N+1)]))
