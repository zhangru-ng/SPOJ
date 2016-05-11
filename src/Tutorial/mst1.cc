// http://www.spoj.com/problems/MST1/

#include <cstdio>
#include <vector>
using namespace std;

#define MAX 20000000

int main() {
    vector<int> dp(MAX+1, 0);
    for (int j = 2; j < dp.size(); j++) {
        dp[j] = dp[j-1] + 1;
        if (j % 2 == 0) {
            dp[j] = min(dp[j], dp[j/2] + 1);
        }
        if (j % 3 == 0) {
            dp[j] = min(dp[j], dp[j/3] + 1);
        }
    }

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", i, dp[n]);
    }
    return 0;
}
