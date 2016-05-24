// http://www.spoj.com/problems/SID/

#include <cstdio>
#include <unordered_map>
using namespace std;

// super fast IO
void scanint(int &x) {
    x = 0;
    int neg = 0;
    register int c = getchar_unlocked();
    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if (c == '-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for (; c > 47 && c < 58; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if (neg) {
        x=-x;
    }
}

void scanchar(char &c) {
    register int x = getchar_unlocked();
    for(; (x < 65 || x > 97); x = getchar_unlocked());
    c = x;
}

int main() {
    int n, m;
    scanint(n);
    scanint(m);

    unordered_multimap<int, int> mp;
    int i;
    int a;
    for (i = 1; i <= n; i++) {
        scanint(a);
        mp.emplace(a, i);
    }

    char op;
    while (m--) {
        scanchar(op);
        scanint(a);
        if (op == 'S' || op == 'D') {
            auto range = mp.equal_range(a);
            if (range.first == range.second) {
                printf("NONE\n");
            } else {
                unordered_multimap<int, int>::iterator prev;
                for (auto it = range.first; it != range.second; ++it) {
                    prev = it;
                }
                printf("%d\n", prev->second);
                if (op == 'D') {
                    mp.erase(prev);
                }
            }
        } else {
            mp.emplace(a, i);
            printf("%d\n", i);
            i++;
        }
    }
    return 0;
}
