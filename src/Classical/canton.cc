// http://www.spoj.com/problems/CANTON/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> v(t);
    map<int, string> mp;
    for (int i = 0; i < t; ++i) {
        cin >> v[i];
        mp.emplace(v[i], "");
    }
    int i = 1, j = 1, d = 1;
    auto it = mp.begin();
    for (int k = 1; k <= (--mp.end())->first; k++) {
        if (k == it->first) {
            it->second = to_string(i) + "/" + to_string(j);
            ++it;
        }
        i -= d;
        j += d;
        if (i < 1) {
            i = 1;
            d = -1;
        }
        if (j < 1) {
            j = 1;
            d = 1;
        }
    }
    for (int i : v) {
        cout << "TERM " << i  << " IS " << mp[i] << '\n';
    }
    return 0;
}
