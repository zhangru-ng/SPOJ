// http://www.spoj.com/problems/HMBY/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> cnt(5);
    for (int i = 0; i < 5; i++) {
        cin >> cnt[i];
    }
    int w;
    cin >> w;

    int base = 32;
    for (int i = 4; i >= 0; i--) {
        int n = min(w / base, cnt[i]);
        w -= base * n;
        if (w == 0) {
            break;
        }
        base /= 2;
    }
    cout << (w == 0 ? "YES" : "NO") << endl;
    return 0;
}
