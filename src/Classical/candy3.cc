// http://www.spoj.com/problems/CANDY3/

#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long c;
            scanf("%lld", &c);
            sum = (sum + c) % n;
        }

        if (sum == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
