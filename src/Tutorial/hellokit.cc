// http://www.spoj.com/problems/HELLOKIT/

#include <iostream>
#include <algorithm>
using namespace std;

string repeat(string &s, int n) {
    string rs;
    for (int i = 0; i < n; i++) {
        rs += s;
    }
    return rs;
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == ".") {
            break;
        }
        int n;
        cin >> n;
        for (int i = 0; i < s.size(); i++) {
            cout << repeat(s, n) << endl;
            rotate(s.begin(), s.begin()+1, s.end());
        }
    }
    return 0;
}
