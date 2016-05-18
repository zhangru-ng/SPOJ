// http://www.spoj.com/problems/FCTRL/

#include <cstdio>
using namespace std;

long long fact_trailing_zeros(long long n) {
    long long count = 0;
    while (n) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        printf("%lld\n", fact_trailing_zeros(n));
    }
    return 0;
}
