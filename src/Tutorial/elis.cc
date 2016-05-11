// http://www.spoj.com/problems/ELIS/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    vector<int> dp(n, 1);
    int lis = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                lis = max(dp[i], lis);
            }
        }
    }

    printf("%d\n", lis);
    return 0;
}
