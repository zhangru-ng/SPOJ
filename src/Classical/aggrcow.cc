// http://www.spoj.com/problems/AGGRCOW/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_X 1000000000

bool isValidDist(vector<long> &stalls, long dist, int c) {
    int n = stalls.size();
    int prev = 0;
    for (int i = 1; i < c; i++) {
        int cur = prev + 1;
        while (cur < n && stalls[cur] - stalls[prev] < dist) {
            cur++;
        }
        if (cur == n) {
            return false;
        }
        prev = cur;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);

        vector<long> stalls(n);
        for(int i = 0; i < n; i++) {
            scanf("%ld", &stalls[i]);
        }
        sort(stalls.begin(), stalls.end());

        long low = 0, high = MAX_X / c + 1;
        while (low < high) {
            long mid = (high + low + 1) / 2;
            if (isValidDist(stalls, mid, c)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        printf("%ld\n", low);

    }
    return 0;
}
