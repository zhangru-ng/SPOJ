// http://www.spoj.com/problems/KNAPSACK/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int size;
    int value;
    Item(int size, int value) : size(size), value(value) { }
};

int main() {
    int s, n;
    scanf("%d %d", &s, &n);
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int size, value;
        scanf("%d %d", &size, &value);
        items.emplace_back(size, value);
    }
    vector<vector<int>> dp(n+1, vector<int>(s+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (items[i-1].size > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].size] + items[i-1].value);
            }
        }
    }
    printf("%d\n", dp[n][s]);
    return 0;
}
