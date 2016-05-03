// http://www.spoj.com/problems/SBANK/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        string s;
        getline(cin, s);
        while (n--) {
            getline(cin, s);
            mp[s]++;
        }
        for (auto p : mp) {
            cout << p.first << " " << p.second << endl;
        }
        if (t != 0) {
            cout << endl;
        }
    }
    return 0;
}
