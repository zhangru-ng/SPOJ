// http://www.spoj.com/problems/BYTESM2/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int> > tiles(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> tiles[i][j];
            }
        }
        int max_num = 0;
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                tiles[i][j] += max(max(tiles[i+1][max(j-1, 0)], tiles[i+1][j]), tiles[i+1][min(j+1, n-1)]);
                max_num = max(max_num, tiles[i][j]);
            }
        }
        cout << max_num << '\n';
    }
    return 0;
}
