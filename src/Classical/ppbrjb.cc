// http://www.spoj.com/problems/PPBRJB/

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int countPrime(int n) {
    vector<bool> flag(n+1, true);
    int count = n - 1;
    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (flag[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (flag[j]) {
                    flag[j] = false;
                    count--;
                }
            }
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> dp(n+1, 1);
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-4];
        }
        printf("%d\n", countPrime(dp[n]));
    }
    return 0;
}
