// http://www.spoj.com/problems/BITCNTR/

#include <cstdio>
using namespace std;

int bitcount(int n) {
    int count = 0;
    while (n) {
        count++;
        n &= n - 1;
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", bitcount(n));
    }
    return 0;
}
