// http://www.spoj.com/problems/HANGOVER/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> v;
    v.push_back(0.0);
    for (int i = 2; i < 278; i++) {
        v.push_back(v[i-2] + 1.0/i);
    }

    double c;
    cin >> c;
    while (c != 0) {
        auto gt = upper_bound(v.begin(), v.end(), c);
        int n = distance(v.begin(), gt);
        cout << n << " card(s)\n";
        cin >> c;
    }

    return 0;
}