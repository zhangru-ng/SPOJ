// http://www.spoj.com/problems/SNGPG/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        if (a == 0) {
            count++;
        }
        if (a <= 1 && b >= 1) {
            count++;
        }
        if (a <= 2 && b >= 2) {
            count++;
        }
        if (a <= 3 && b >= 3) {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
