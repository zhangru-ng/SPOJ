// http://www.spoj.com/problems/AP2/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long thirdTerm, thirdLastTerm, sum;
        cin >> thirdTerm >> thirdLastTerm >> sum;
        long long n = 2 * sum / (thirdTerm+thirdLastTerm);
        long long d = (thirdLastTerm - thirdTerm)/(n-5);
        long long beg = thirdTerm - 2 * d;
        cout << n << endl;
        for (long long i = 0; i < n; i++) {
            cout << beg + (i*d) << " ";
        }
        cout << endl;
    }
    return 0;
}
