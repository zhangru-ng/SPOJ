// http://www.spoj.com/problems/ANAG/

#include <iostream>
#include <vector>
using namespace std;

vector<int> count_char(string& s) {
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        vector<int> count_a = count_char(a);
        vector<int> count_b = count_char(b);
        int i;
        for (i = 0; i < 26; i++) {
            if (count_a[i] != count_b[i]) {
                break;
            }
        }
        if (i == 26) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
