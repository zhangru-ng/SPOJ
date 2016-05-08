// http://www.spoj.com/problems/PT07Z/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> &tree, int u, vector<bool> &visited, int &max_len) {
    visited[u] = true;
    int local_max = 0;
    int local_2nd_max = 0;
    for (int v : tree[u]) {
        if (!visited[v]) {
            int len = 1 + dfs(tree, v, visited, max_len);
            if (len > local_max) {
                local_2nd_max = local_max;
                local_max = len;
            } else if (len > local_2nd_max) {
                local_2nd_max = len;
            }
        }
    }
    max_len = max(local_max + local_2nd_max, max_len);
    return local_max;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<bool> visited(n+1, false);
    int max_len = 0;
    dfs(tree, 1, visited, max_len);
    cout << max_len << endl;
    return 0;
}
