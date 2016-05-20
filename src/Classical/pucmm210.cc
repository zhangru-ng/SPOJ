// http://www.spoj.com/problems/PUCMM210/

#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 1000000
#define MOD 1000000003

void precompute(vector<long long>& sf) {
    long long f = 0;
    for (long long i = 1; i <= MAX_N; i++) {
        f = (f + i*i*i) % MOD;
        sf[i] = (sf[i-1] + f) % MOD;
    }
}

int main() {
    vector<long long> sf(MAX_N+1, 0);
    precompute(sf);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", sf[n]);
    }
    return 0;
}
