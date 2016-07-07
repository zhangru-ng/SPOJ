#!/usr/bin/env python3

# http://www.spoj.com/problems/BISHOPS/

from sys import stdin

for line in stdin:
  n = int(line.strip())
  print(1 if n == 1 else 2 * n - 2)
