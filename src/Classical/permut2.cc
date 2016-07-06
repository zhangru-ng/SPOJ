// http://www.spoj.com/problems/PERMUT2/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n != 0) {
        vector<int> per(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> per[i];
        }
        vector<int> inv(n+1);
        bool ambiguous = true;
        for (int i = 1; i <= n; i++) {
            inv[per[i]] = i;
            if (inv[per[i]] != per[per[i]]) {
                ambiguous = false;
                break;
            }
        }
        cout << (ambiguous ? "ambiguous" : "not ambiguous") << '\n';
        cin >> n;
    }
    return 0;
}
