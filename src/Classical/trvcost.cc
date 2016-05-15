// http://www.spoj.com/problems/TRVCOST/

#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using pi_t = pair<int, int>;

void dijkstra(vector<vector<pi_t>> &graph, int src, vector<int> &dist) {
    priority_queue<pi_t, vector<pi_t>, greater<pi_t>> pq;
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second;
        if (t.first > dist[u]) {
            continue;
        }
        for (auto p : graph[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<pi_t>> graph(501);

    for (int i = 0; i < n; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    int u, q;
    scanf("%d %d", &u, &q);

    vector<int> dist(501, INT_MAX);
    dijkstra(graph, u, dist);

    while (q--) {
        int v;
        scanf("%d", &v);
        if (dist[v] == INT_MAX) {
            printf("NO PATH\n");
        } else {
            printf("%d\n", dist[v]);
        }
    }
    return 0;
}
