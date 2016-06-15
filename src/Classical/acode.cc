// http://www.spoj.com/problems/ACODE/

#include <iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    while (s != "0") {
        int pre = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            int temp = cur;
            if (s[i] == '0') {
                if (s[i-1] == '0') {
                    cur = 0;
                    break;
                }
                cur = pre;
            } else if (s[i-1] == '1' || s[i-1] == '2' && s[i] < '7') {
                cur = pre + cur;
            }
            pre = temp;
        }
        cout << cur << endl;
        getline(cin, s);
    }
    return 0;
}
