// http://www.spoj.com/problems/OPCPRIME/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);

    if (n % 2 == 0) {
        printf("2\n");
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            printf("%d\n", i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 2) {
        printf("%lld\n", n);
    }

    return 0;
}
