// http://www.spoj.com/problems/DOUGHNUT/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int c, k, w;
        cin >> c >> k >> w;
        if (c * w <= k) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
