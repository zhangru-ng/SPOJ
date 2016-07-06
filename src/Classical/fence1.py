#!/usr/bin/env python3

# http://www.spoj.com/problems/FENCE1/

import math

L = int(input())
while L != 0:
    print('{0:.2f}'.format(0.5*L*L/math.pi))
    L = int(input())
