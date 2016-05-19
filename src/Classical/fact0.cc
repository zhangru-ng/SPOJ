// http://www.spoj.com/problems/FACT0/

#include <cstdio>
using namespace std;

int main() {
    unsigned long long n;
    while (true) {
        scanf("%llu", &n);
        if (n == 0) {
            break;
        }
        for (unsigned long long fact = 2; fact * fact <= n; fact++) {
            if (n % fact == 0) {
                int cnt = 0;
                while (n % fact == 0) {
                    cnt++;
                    n /= fact;
                }
                printf("%llu^%d ", fact, cnt);
            }
        }

        if (n > 1) {
            printf("%llu^1", n);
        }
        printf("\n");
    }
    return 0;
}
