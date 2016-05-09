// http://www.spoj.com/problems/COUNTISL/

#include <iostream>
#include <vector>
using namespace std;

const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                  {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(vector<string> &grid, int i, int j, int n, int m) {
    grid[i][j] = '.';
    for (auto &d : dirs) {
        int x = i + d.first;
        int y = j + d.second;
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '#') {
            dfs(grid, x, y, n, m);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    dfs(grid, i, j, n, m);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
