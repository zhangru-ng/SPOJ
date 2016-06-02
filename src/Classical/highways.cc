// http://www.spoj.com/problems/HIGHWAYS/

#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using pi_t = pair<int, int>;

void dijkstra(vector<vector<pi_t>> &graph, int src, int des, vector<int> &dist) {
    priority_queue<pi_t, vector<pi_t>, greater<pi_t>> pq;
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int u = t.second;
        if (u == des) {
            break;
        }
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
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, s, e;
        scanf("%d %d %d %d", &n, &m, &s, &e);
        vector<vector<pi_t>> graph(n+1);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        vector<int> dist(n+1, INT_MAX);
        dijkstra(graph, s, e, dist);

        if (dist[e] == INT_MAX) {
            printf("NONE\n");
        } else {
            printf("%d\n", dist[e]);
        }
    }
    return 0;
}
