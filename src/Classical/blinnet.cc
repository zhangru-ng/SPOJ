// http://www.spoj.com/problems/BLINNET/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 1);
        for (int i = 0; i < n+1; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
            parent[px] = py;

        }
    }
};

struct Edge {
    int u;
    int v;
    int w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Edge> graph;
        for (int u = 1; u <= n; u++) {
            string name;
            int m;
            cin >> name >> m;
            int v, w;
            for (int j = 0; j < m; j++) {
                cin >> v >> w;
                graph.emplace_back(u, v, w);
            }
        }

        sort(graph.begin(), graph.end(), [](const Edge& e1, const Edge& e2){return e1.w < e2.w;});
        DisjointSet dset(n);
        int tot_cost = 0;
        for (Edge& e : graph) {
            if (dset.find(e.u) != dset.find(e.v)) {
                tot_cost += e.w;
                dset.unite(e.u, e.v);
            }
        }
        cout << tot_cost << "\n";
    }
    return 0;
}
