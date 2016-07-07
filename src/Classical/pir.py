#!/usr/bin/env python3

# http://www.spoj.com/problems/PIR/

from math import sqrt

T = int(input())
for i in range(T):
    U, V, w, W, v, u = map(int, input().split())
    X = (w - U + v) * (U + v + w)
    x = (U - v + w) * (v - w + U)
    Y = (u - V + w) * (V + w + u)
    y = (V - w + u) * (w - u + V)
    Z = (v - W + u) * (W + u + v)
    z = (W - u + v) * (u - v + W)
    a = sqrt(x * Y * Z)
    b = sqrt(y * X * Z)
    c = sqrt(z * X * Y)
    d = sqrt(x * y * z)
    volume = sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192*u*v*w)
    print("{0:.4f}".format(volume))
