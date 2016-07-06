#!/usr/bin/env python3

# http://www.spoj.com/problems/ANARC08B/

seg_map = {'063': 0, '010': 1, '093': 2, '079': 3, '106': 4,
         '103': 5, '119': 6, '011': 7, '127': 8, '107': 9}
d_map = dict([reversed(i) for i in seg_map.items()])

line = input()
while line != 'BYE':
    A = 0
    i = 0
    while line[i] != '+':
        A = A * 10 + seg_map[line[i:i+3]]
        i += 3
    i += 1
    B = 0
    while line[i] != '=':
        B = B * 10 + seg_map[line[i:i+3]]
        i += 3

    res = A + B
    segs = []
    while res != 0:
        segs.append(d_map[res % 10])
        res //= 10
    print(line+''.join(reversed(segs)))
    line = input()
