// http://www.spoj.com/problems/PRIME1/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void generatePrime(int m, int n) {
    vector<int> primes(1, 2);
    // find all primes between 3 and sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        auto upper_it = upper_bound(primes.begin(), primes.end(), sqrt(i));
        if (none_of(primes.begin(), upper_it, [i](int p) {return i % p == 0;})) {
            primes.push_back(i);
        }
    }

    for (int i = max(2, m); i <= n; i++) {
        auto upper_it = upper_bound(primes.begin(), primes.end(), sqrt(i));
        if (none_of(primes.begin(), upper_it, [i](int p) {return i % p == 0;})) {
            cout << i << '\n';
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        generatePrime(m, n);
        if (t) {
            cout << endl;
        }
    }
    return 0;
}
