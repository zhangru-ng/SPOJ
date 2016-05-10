// http://www.spoj.com/problems/AMR10F/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, d;
        cin >> n >> a >> d;
        cout << (2*a + (n-1)*d) * n / 2 << endl;
    }
    return 0;
}
