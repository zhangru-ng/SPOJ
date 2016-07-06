// http://www.spoj.com/problems/STAMPS/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int s, n;
        cin >> s >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        int i;
        for (i = 0; i < n; i++) {
            s -= v[i];
            if (s <= 0) {
                break;
            }
        }

        cout << "Scenario #" << c << ":\n";
        if (s <= 0) {
            cout << i + 1;
        } else {
            cout << "impossible";
        }
        cout << "\n\n";
    }

    return 0;
}
