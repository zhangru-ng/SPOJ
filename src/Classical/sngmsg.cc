// http://www.spoj.com/problems/SNGMSG/

#include <iostream>
using namespace std;

string decrypt(string& msg, string& key) {
    int k = 0;
    int dir = 1;
    string res;
    for (char c : msg) {
        res += 'a' + (c - 'a' - (key[k] - '0') + 26) % 26;
        k += dir;
        if (k == key.size()) {
            k = key.size() - 1;
            dir = -1;
        } else if (k == -1) {
            k = 0;
            dir = 1;
        }

    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string key, msg;
        cin >> key >> msg;
        cout << decrypt(msg, key) << endl;
    }
    return 0;
}
