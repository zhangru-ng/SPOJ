// http://www.spoj.com/problems/PRO/

#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> box;
    long long cost = 0;

    while (n--) {
        int k;
        scanf("%d", &k);

        while (k--) {
            int r;
            scanf("%d", &r);
            box[r]++;
        }

        cost += box.rbegin()->first - box.begin()->first;
        if (--box.rbegin()->second == 0) {
            box.erase(--box.end());
        }
        if (--box.begin()->second == 0) {
            box.erase(box.begin());
        }
    }
    printf("%lld", cost);
    return 0;
}
