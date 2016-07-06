#!/usr/bin/env python3

# http://www.spoj.com/problems/NY10A/

seqs = { 'TTT': 0, 'TTH': 1, 'THT': 2, 'THH': 3, 'HTT': 4, 'HTH': 5, 'HHT': 6, 'HHH': 7 }

T = int(input())
for i in range(T):
    n = int(input())
    s = input()
    count = [0] * 8
    for j in range(38):
        if s[j:j+3] in seqs:
            count[seqs[s[j:j+3]]] += 1
    print(n, ' '.join(map(str, count)))
