// http://www.spoj.com/problems/DCRYPT/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int key;
        string msg;
        cin >> key >> msg;
        string res;
        for (char c : msg) {
            if (c == '.') {
                res += ' ';
                continue;
            }
            char d = 'a' + (tolower(c) - 'a' + key) % 26;
            if (key > 25) {
                res += islower(c) ? toupper(d) : tolower(d);
            } else {
                res += islower(c) ? d : toupper(d);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
