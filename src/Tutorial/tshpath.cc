// http://www.spoj.com/problems/TSHPATH/

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

using pi_t = pair<int, int>;
int dijkstra(vector<vector<int>> &edges, vector<vector<int>> &weights, int src, int des) {
    priority_queue<pi_t, vector<pi_t>, greater<pi_t>> pq;
    vector<int> dist(edges.size(), INT_MAX);
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        pi_t p = pq.top();
        pq.pop();
        int v = p.second;
        int d = p.first;
        if (v == des) {
            break;
        }
        if (dist[v] < d) {
            continue;
        }
        for (int i = 0; i < edges[v].size(); i++) {
            if (dist[edges[v][i]] > dist[v] + weights[v][i]) {
                dist[edges[v][i]] = dist[v] + weights[v][i];
                pq.emplace(dist[edges[v][i]], edges[v][i]);
            }
        }
    }
    return dist[des];
}

int main() {
    int s, n;
    scanf("%d", &s);
    while (s--) {
        unordered_map<string, int> roster;
        int n;
        scanf("%d", &n);
        vector<vector<int>> edges(n+1);
        vector<vector<int>> weights(n+1);
        for (int i = 1; i <= n; i++) {
            char name[11];
            scanf("%s", name);
            roster.emplace(name, i);
            int p;
            scanf("%d", &p);
            while (p--) {
                int nr, cost;
                scanf("%d %d", &nr, &cost);
                edges[i].push_back(nr);
                weights[i].push_back(cost);
            }
        }

        int r;
        scanf("%d", &r);
        while (r--) {
            char n1[11], n2[11];
            scanf("%s %s", n1, n2);
            int src = roster[string(n1)];
            int des = roster[string(n2)];
            printf("%d\n", dijkstra(edges, weights, src, des));
        }
    }
    return 0;
}
