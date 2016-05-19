// http://www.spoj.com/problems/IITWPC4I/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) {
            return;
        }
        if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
            parent[px] = py;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

struct Edge {
    int u;
    int v;
    int c;
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

long long petya_repair(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2){return e1.c < e2.c;});
    long long cost = 0;
    DisjointSet ds(n);
    for (auto& e: edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            cost += e.c;
            ds.unite(e.u, e.v);
        }
    }
    for (int i = 1; i < n; i++)
        if (ds.find(0) != ds.find(i))
            return -1;
    return cost;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<Edge> edges;

        int is_milkman;
        for (int i = 0; i < n; i++) {
            scanf("%d", &is_milkman);
            if (is_milkman == 1) {
                edges.emplace_back(i, n, 0);
            }
        }

        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            edges.emplace_back(u - 1, v - 1, c);
        }

        long long cost = petya_repair(edges, n + 1);
        if (cost == -1) {
            printf("impossible\n");
        } else {
            printf("%lld\n", cost);
        }
    }
    return 0;
}

