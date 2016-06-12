// http://www.spoj.com/problems/EELCS/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}

