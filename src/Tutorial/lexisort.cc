// http://www.spoj.com/problems/LEXISORT/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> vs(n);
        for (int i = 0; i < n; i++) {
            cin >> vs[i];
        }
        sort(vs.begin(),vs.end());
        for (int i = 0; i < n; i++) {
            cout << vs[i] << endl;
        }
    }
    return 0;
}

