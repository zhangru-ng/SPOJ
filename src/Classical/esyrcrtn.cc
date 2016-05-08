// http://www.spoj.com/problems/ESYRCRTN/

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    const vector<int> res{1, 4, 6, 5, 2, 0};
    while (t--) {
        long long n;
        scanf("%lld", &n);
        printf("%d\n", res[(n-1)%6]);
    }
    return 0;
}
