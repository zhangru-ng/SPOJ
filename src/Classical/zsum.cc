// http://www.spoj.com/problems/ZSUM/

#include <iostream>
using namespace std;

constexpr int MOD = 10000007;

int pow_mod(long long base, int exp) {
    long long res = 1;
    base = base % MOD;
    while (exp) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    while (n != 0 || k != 0) {
        int a = (pow_mod(n-1, k) * 2) % MOD;
        int b = pow_mod(n, k);
        int c = (pow_mod(n-1, n-1) * 2) % MOD;
        int d = pow_mod(n, n);
        cout << (a+b+c+d) % MOD << '\n';
        cin >> n >> k;
    }
    return 0;
}
