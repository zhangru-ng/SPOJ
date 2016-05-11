// http://www.spoj.com/problems/FACTCG/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define MAX_SIZE 100000

void sieve(vector<int> &sieve_table) {
    int n = sieve_table.size();
    for (int i = 2; i <= sqrt(n); i++) {
        if (sieve_table[i] == 0) {
            for (int j = i*i; j < n; j += i) {
                if (sieve_table[j] == 0) {
                    sieve_table[j] = i;
                }
            }
        }
    }
}

int main() {
    vector<int> sieve_table(MAX_SIZE+1, 0);
    sieve(sieve_table);
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("1");

        while (sieve_table[n] != 0) {
            printf(" x %d", sieve_table[n]);
            n /= sieve_table[n];
        }

        if (n > 1) {
            printf(" x %d", n);
        }

        printf("\n");
    }
    return 0;
}
