// http://www.spoj.com/problems/CSTREET/

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
        rank.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        }
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            if (rank[px] == rank[py]) {
                rank[py]++
            }
            parent[px] = py;
        }
    }
};

struct Edge {
    int a;
    int b;
    long long c;
    Edge(int a, int b, long long c) : a(a), b(b), c(c) {}
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int p, n, m;
        scanf("%d %d %d", &p, &n, &m);
        DisjointSet ds(n);
        vector<Edge> edges;
        while (m--) {
            int a, b;
            long long c;
            scanf("%d %d %lld", &a, &b, &v);
            edges.emplace_back(a, b, c);
        }
        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2){return e1.c < e2.c;});
        int cost = 0;
        for (auto e : edges) {
            if (ds.find(e.a) != ds.find(e.b)) {
                ds.unite(e.a, e.b);
                cost += e.c;
            }
        }
        printf("%d\n", cost * p);
    }
    return 0;
}
