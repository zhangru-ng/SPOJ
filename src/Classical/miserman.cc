// http://www.spoj.com/problems/MISERMAN/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = m - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            b[i][j] += min(min(b[i+1][max(j-1, 0)], b[i+1][j]), b[i+1][min(j+1, n-1)]);
        }
    }
    cout << *min_element(b[0].begin(), b[0].end()) << '\n';

    return 0;
}
