// http://www.spoj.com/problems/FEELUCK/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

using psi_t = pair<string, int>;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <=t; i++) {
        map<int, vector<string>, greater<int>> mp;
        string addr;
        int cnt;
        for (int j = 0; j < 10; j++) {
            cin >> addr >> cnt;
            mp[cnt].push_back(addr);
        }
        cout << "Case #" << i << ":" << endl;
        for (auto s : mp.begin()->second) {
            cout << s << endl;
        }
    }
    return 0;
}
