// http://www.spoj.com/problems/CANDY4/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define MAX_N 20000

vector<double> ln_prefix_sum;

void precompute() {
    int n = 2 * MAX_N + 1;
    ln_prefix_sum.resize(n, 0);
    for (int i = 1; i < n; i++) {
        ln_prefix_sum[i] = ln_prefix_sum[i-1] + log(i);
    }
}

// ln C(n, m) = sum{ln(i) where i <- [m+1, n]} - sum{ln(i) where i <- [2, m-n]}
double ln_nCr(int n, int r) {
    return ln_prefix_sum[n] - ln_prefix_sum[r] - ln_prefix_sum[n-r];
}

int main() {
    precompute();

    int n;
    double p;
    int t = 1;
    while (scanf("%d %lf", &n, &p) != EOF) {
        double e = 0.0;
        for (int i = 0; i < n; i++) {
            e += (n-i) * (exp(ln_nCr(n+i, i) + (n+1)*log(p) + i*log(1-p)) +
                          exp(ln_nCr(n+i, i) + (n+1)*log(1-p) + i*log(p)));
        }
        printf("Case %d: %.6f\n", t, e);
        t++;
    }
}
