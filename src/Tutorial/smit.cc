// http://www.spoj.com/problems/SMIT/

#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        int n;
        scanf("%d", &n);
        if (n % 2) {
            printf("Case %d: %d\n", i, -(n+1)/2);
        } else {
            printf("Case %d: %d\n", i, n/2);
        }

    }
    return 0;
}
