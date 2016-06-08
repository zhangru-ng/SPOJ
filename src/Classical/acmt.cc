// http://www.spoj.com/problems/ACMT/

#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int e, n;
        scanf("%d %d", &e, &n);
        if (e >= 2 * n) {
            printf("%d\n", n);
        } else if (n >= 2 * e) {
            printf("%d\n", e);
        } else {
            printf("%d\n", (e+n)/3);
        }
    }
    return 0;
}
