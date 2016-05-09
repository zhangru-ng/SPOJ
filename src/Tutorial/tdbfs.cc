// http://www.spoj.com/problems/TDBFS/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &graph, int i) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[i] = true;
    q.push(i);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int v : graph[t]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void dfs_(vector<vector<int>> &graph, int i, vector<bool> &visited) {
    visited[i] = true;
    cout << i << " ";
    for (int v : graph[i]) {
        if (!visited[v]) {
            dfs_(graph, v, visited);
        }
    }
}

void dfs(vector<vector<int>> &graph, int i) {
    vector<bool> visited(graph.size(), false);
    dfs_(graph, i, visited);
}

int main() {
    int t;
    cin >> t;
    for (int g = 1; g <= t; g++) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n+1);
        for (int i = 1; i <= n; i++) {
            int v, m;
            cin >> v >> m;
            for (int j = 0; j < m; j++) {
                int u;
                cin >> u;
                graph[v].push_back(u);
            }
        }
        int v, i;
        cout << "graph " << g << endl;
        while (cin >> v >> i) {
            if (v == 0 && i == 0) {
                break;
            }
            i == 0 ? dfs(graph, v) : bfs(graph, v);
            cout << endl;
        }
    }
    return 0;
}
