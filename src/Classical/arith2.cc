// http://www.spoj.com/problems/ARITH2/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long res = 0;
        cin >> res;
        char op;
        while (cin >> op) {
            if (op == '=') {
                cout << res << endl;
                break;
            }
            int num;
            cin >> num;
            if (op == '+') {
                res += num;
            } else if (op == '-') {
                res -= num;
            } else if (op == '*') {
                res *= num;
            } else {
                res /= num;
            }
        }
    }
    return 0;
}
