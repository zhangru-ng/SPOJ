// http://www.spoj.com/problems/LOSTNSURVIVED/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
    map<int, int> size_map; // <size, count>
    // decrement size count by 1, erase element if count drop to 0
    void remove(int sz) {
        auto it = size_map.find(sz);
        if (it->second == 1) {
            size_map.erase(it);
        } else {
            it->second--;
        }
    }
public:
    DisjointSet(int n) {
        size.resize(n+1, 1);
        size_map.empalce(1, n);
        for (int i = 0; i <= n; i++) {
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
        if (px == py) {
            return;
        }
        remove(size[px]);
        remove(size[py]);
        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
            size_map[size[px]]++;
        } else {
            parent[px] = py;
            size[py] += size[px];
            size_map[size[py]]++;
        }
    }

    int max_min_diff() {
        if (size_map.size() == 1) {
            return 0;
        } else {
            return size_map.rbegin()->first - size_map.begin()->first;
        }
    }
};

int main() {
    int n, q;
    scanf("%d, %d", &n, &q);
    DisjointSet ds(n);
    while (q--) {
        int a, b;
        scanf("%d, %d", &a, &b);
        ds.unite(a, b);
        printf(ds.max_min_diff());
    }
    return 0;
}
