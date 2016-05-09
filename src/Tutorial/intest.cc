// http://www.spoj.com/problems/INTEST/

#include <cstdio>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int count = 0;
    while (n--) {
        int t;
        scanf("%d", &t);
        if (t % k == 0) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
