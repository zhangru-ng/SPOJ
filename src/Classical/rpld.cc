// http://www.spoj.com/problems/RPLD/

#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, r;
        scanf("%d %d", &n, &r);
        vector<unordered_set<int>> students(n+1);
        bool possible = true;
        while (r--) {
            int a, c;
            scanf("%d %d", &a, &c);
            if (possible) {
                if (students[a].find(c) != students[a].end()) {
                    possible = false;
                }
                students[a].insert(c);
            }
        }
        if (possible) {
            printf("Scenario #%d: possible\n", i);
        } else {
            printf("Scenario #%d: impossible\n", i);
        }
    }
    return 0;
}
