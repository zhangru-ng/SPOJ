// http://www.spoj.com/problems/WILLITST/

#include <cstdio>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    if (n <= 1 || (n & (n-1)) == 0) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }
    return 0;
}
