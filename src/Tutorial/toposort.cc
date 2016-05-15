// http://www.spoj.com/problems/TOPOSORT/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n+1);
    vector<int> in_degree(n+1, 0);
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        in_degree[y]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> order;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }
    if (order.size() == n) {
        for (int v : order) {
            printf("%d ", v);
        }
    } else {
        printf("Sandro fails.");
    }

    return 0;
}
