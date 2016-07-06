#!/usr/bin/env python3

# http://www.spoj.com/problems/GIRLSNBS/

from math import ceil

G, B = map(int, input().split())

while G != -1 and B != -1:
    if G < B:
        G, B = B, G

    print(ceil(G / (B+1)))
    G, B = map(int, input().split())
