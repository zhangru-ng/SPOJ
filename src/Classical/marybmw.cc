// http://www.spoj.com/problems/MARYBMW/

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
    long long v;
    Edge(int a, int b, long long v) : a(a), b(b), v(v) {}
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        DisjointSet ds(n);
        vector<Edge> edges;
        while (m--) {
            int a, b;
            long long v;
            scanf("%d %d %lld", &a, &b, &v);
            edges.emplace_back(a, b, v);
        }
        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2){return e1.v > e2.v;});
        for (int i = 0; i < edges.size(); i++) {
            ds.unite(edges[i].a, edges[i].b);
            if (ds.find(1) == ds.find(n)) {
                printf("%lld\n", edges[i].v);
                break;
            }
        }
        if (ds.find(1) != ds.find(n)) {
            printf("-1\n");
        }
    }
    return 0;
}
