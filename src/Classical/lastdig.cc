// http://www.spoj.com/problems/LASTDIG/

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int res = 1;
        if (b > 0) {
            a = a % 10;
            b = b % 4 + 4;
            while (b--) {
                res = (res * a) % 10;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
