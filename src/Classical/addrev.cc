// http://www.spoj.com/problems/ADDREV/

#include <cstdio>

long reverse_int(long x) {
    long r = 0;
    while (x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%ld\n", reverse_int(reverse_int(a) + reverse_int(b)));
    }
    return 0;
}
