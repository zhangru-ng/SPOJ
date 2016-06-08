// http://www.spoj.com/problems/FOXLINGS/

#include <cstdio>
#include <unordered_map>
using namespace std;

class DisjointSet {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int count;
public:
    DisjointSet(int n) : count(n) {}

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        if (parent.find(x) == parent.end()) {
            parent.emplace(x, x);
            rank.emplace(x, 1);
        }
        if (parent.find(y) == parent.end()) {
            parent.emplace(y, y);
            rank.emplace(y, 1);
        }
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        }
        count--;
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
            parent[px] = py;
        }
    }

    int get_count() {
        return count;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    DisjointSet dset(n);
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        dset.unite(x, y);
    }
    printf("%d\n", dset.get_count());
    return 0;
}
