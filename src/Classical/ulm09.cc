// http://www.spoj.com/problems/ULM09/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge {
    int x;
    int y;
    int w;
    Edge(int x, int y, int w) : x(x), y(y), w(w) {}
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void link(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            if (rank[p1] == rank[p2]) {
                rank[p2]++;
            }
            parent[p1] = p2;
        }
    }
};

int main() {
    while (true) {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) {
            break;
        }

        vector<Edge> edges;
        int tot_weight = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.emplace_back(x, y, z);
            tot_weight += z;
        }

        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2){return e1.w < e2.w;});

        DisjointSet dset(m);
        int min_weight = 0;
        for (const Edge& e : edges) {
            if (dset.find(e.x) != dset.find(e.y)) {
                min_weight += e.w;
                dset.link(e.x, e.y);
            }
        }
        printf("%d\n", tot_weight - min_weight);
    }
    return 0;
}
