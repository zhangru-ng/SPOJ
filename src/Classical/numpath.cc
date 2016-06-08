// http://www.spoj.com/problems/NUMPATH/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> dp(r, vector<int>(c, 1));
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        cout << dp[r-1][c-1] << endl;
    }
    return 0;
}
