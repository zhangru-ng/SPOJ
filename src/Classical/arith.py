#!/usr/bin/env python3

# http://www.spoj.com/problems/ARITH/

T = int(input())
for i in range(T):
    expr = input()
    if '+' in expr:
        a, b = expr.split('+')
        c = str(int(a)+int(b))
        m = max(len(a), len(b)+1)
        n = max(len(b)+1, len(c))
        print('{0}\n{1}\n{2}\n{3}\n'.format(a.rjust(m), ('+'+b).rjust(m), ('-'*n).rjust(m), c.rjust(m)))
    elif '-' in expr:
        a, b = expr.split('-')
        c = str(int(a)-int(b))
        m = max(len(a), len(b)+1)
        n = max(len(b)+1, len(c))
        print('{0}\n{1}\n{2}\n{3}\n'.format(a.rjust(m), ('-'+b).rjust(m), ('-'*n).rjust(m), c.rjust(m)))
    else:
        a, b = expr.split('*')
        c = str(int(a)*int(b))
        m = max(len(b)+1, len(str(int(a)*int(b[-1]))))
        n = max(len(a), len(b)+1, len(c))
        print('{0}\n{1}\n{2}'.format(a.rjust(n), ('*'+b).rjust(n), ('-'*m).rjust(n)))
        if len(b) > 1:
            for i in range(len(b)):
                print((str(int(a)*int(b[-(i+1)]))+ ' '*i).rjust(n).rstrip())
            print(('-'*len(c)).rjust(n))
        print(c.rjust(n), end='\n\n')

