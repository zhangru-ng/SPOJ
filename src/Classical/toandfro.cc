// http://www.spoj.com/problems/TOANDFRO/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n) {
        string encrypted;
        cin >> encrypted;

        vector<string> rect;
        int end = encrypted.size() / n;
        for (int i = 0; i < end; i++) {
            string t = encrypted.substr(i * n, n);
            if (i % 2) {
                reverse(t.begin(), t.end());
                rect.push_back(t);
            } else {
                rect.push_back(t);
            }
        }
        string msg;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rect.size(); j++) {
                msg += rect[j][i];
            }
        }
        cout << msg << "\n";

        cin >> n;
    }
    return 0;
}
