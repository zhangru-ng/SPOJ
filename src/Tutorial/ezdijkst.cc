// http://www.spoj.com/problems/EZDIJKST/

#include <cstdio>
#include <vector>
#include <climits>
#include <set>
using namespace std;

long long dijkstra(vector<vector<pair<int, int>>> &graph, int src, int des) {
    vector<long long> min_dist(graph.size(), LLONG_MAX);
    min_dist[src] = 0;
    set<pair<long long, int>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        int v = pq.begin()->second;
        if (v == des) {
            break;
        }
        pq.erase(pq.begin());
        for (auto edge : graph[v]) {
            if (min_dist[edge.first] > min_dist[v] + edge.second) {
                pq.erase(make_pair(min_dist[edge.first], edge.first));
                min_dist[edge.first] = min_dist[v] + edge.second;
                pq.emplace(min_dist[edge.first], edge.first);
            }
        }
    }
    return min_dist[des];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<vector<pair<int, int>>> graph(n+1);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d %d %d",&a, &b, &c);
            graph[a].emplace_back(b, c);
        }
        int src, des;
        scanf("%d %d", &src, &des);
        long long d = dijkstra(graph, src, des);
        if (d == LLONG_MAX) {
            printf("NO\n");
        } else {
            printf("%lld\n", d);
        }

    }
}
