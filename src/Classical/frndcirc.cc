// http://www.spoj.com/problems/FRNDCIRC/

#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
public:
    // make set and return its id
    int make_set() {
        parent.push_back(parent.size());
        size.push_back(1);
        return parent.back();
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return size[px];
        }
        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px];
        }
        return size[parent[px]];
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        DisjointSet ds;
        unordered_map<string, int> id_map;
        while (n--) {
            char cn1[21], cn2[21];
            scanf("%s %s", cn1, cn2);
            string name1(cn1);
            string name2(cn2);

            if (id_map.find(name1) == id_map.end()){
                id_map.emplace(name1, ds.make_set());
            }
            if (id_map.find(name2) == id_map.end()){
                id_map.emplace(name2, ds.make_set());
            }
            printf("%d\n", ds.unite(id_map[name1], id_map[name2]));
        }

    }
    return 0;
}
