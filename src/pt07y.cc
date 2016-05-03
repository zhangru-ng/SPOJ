// http://www.spoj.com/problems/PT07Y/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, int src, vector<bool> &visited) {
    visited[src] = true;
    for (int nei : graph[src]) {
        if (!visited[nei]) {
            dfs(graph, nei, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n != m + 1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<vector<int>> graph(n+1, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    dfs(graph, 1, visited);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
