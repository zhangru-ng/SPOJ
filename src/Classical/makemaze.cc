//http://www.spoj.com/problems/MAKEMAZE/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void checkOpening(vector<string> &graph, int i, int j, int &count, pair<int, int> &entry) {
    if (graph[i][j] == '.') {
        count++;
        entry = {i, j};
    }
}

int countOpening(vector<string> &graph, int m, int n, pair<int, int> &entry) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        checkOpening(graph, i, 0, count, entry);
        if (n != 1) {
            checkOpening(graph, i, n-1, count, entry);
        }
    }
    for (int j = 1; j < n-1; j++) {
        checkOpening(graph, 0, j, count, entry);
        if (m != 1) {
            checkOpening(graph, m-1, j, count, entry);
        }
    }
    return count;
}

bool bfs(vector<string> &graph, int i, int j, int m, int n) {
    const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    q.emplace(i, j);
    graph[i][j] = '#';
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto d : dirs) {
            int x = p.first + d.first;
            int y = p.second + d.second;
            if (x >= 0 && x  < m && y >= 0 && y < n && graph[x][y] == '.') {
                if (x == 0 || x == m-1 || y == 0 || y == n-1) {
                    return true;
                }
                graph[x][y] = '#';
                q.emplace(x, y);
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<string> graph(m);
        for (int i = 0; i < m; i++) {
            cin >> graph[i];
        }
        pair<int, int> entry;
        if (countOpening(graph, m, n, entry) == 2 && bfs(graph, entry.first, entry.second, m, n)) {
            cout << "valid" << endl;
        } else {
            cout << "invalid" << endl;
        }
    }
    return 0;
}
