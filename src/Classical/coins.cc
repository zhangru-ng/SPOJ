// http://www.spoj.com/problems/COINS/

#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> memo;

long long coins(int n) {
    if (n == 0) {
        return 0;
    }
    if (memo[n] == 0) {
        long long c = max(static_cast<long long>(n), coins(n/2) + coins(n/3) + coins(n/4));
        memo[n] = c;
    }
    return memo[n];
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", coins(n));
    }
    return 0;
}
