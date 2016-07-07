// http://www.spoj.com/problems/OLOLO/

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        int x;
        cin >> x;
        res ^= x;
    }
    cout << res << '\n';
    return 0;
}
