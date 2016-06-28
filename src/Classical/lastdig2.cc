// http://www.spoj.com/problems/LASTDIG2/

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        long long b;
        cin >> s >> b;

        int res = 1;
        if (b > 0) {
            int a = s.back() - '0';
            b = b % 4 + 4;
            while (b--) {
                res = (res * a) % 10;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
