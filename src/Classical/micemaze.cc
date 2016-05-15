// http://www.spoj.com/problems/MICEMAZE/

#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

using pi_t = pair<int, int>;

int dijkstra(vector<vector<pi_t>> &graph, int src, int threshold) {
    vector<int> dist(graph.size(), INT_MAX);
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

    return count_if(dist.begin(), dist.end(), [threshold](int d){return d <= threshold;});
}

int main() {
    int n, e, t, m;
    scanf("%d %d %d %d", &n, &e, &t, &m);

    vector<vector<pi_t>> graph(n+1);
    while (m--) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        // reverse edges, convert to Single-destination shortest-paths problem
        graph[b].emplace_back(a, w);
    }

    printf("%d\n", dijkstra(graph, e, t));

    return 0;
}
