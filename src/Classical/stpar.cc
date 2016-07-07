// http://www.spoj.com/problems/STPAR/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n) {
        stack<int> st;
        int cur = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == cur) {
                cur++;
                while (!st.empty() && st.top() == cur) {
                    cur++;
                    st.pop();
                }
            } else {
                st.push(x);
            }
        }
        cout << (st.empty() ? "yes" : "no") << '\n';
        cin >> n;
    }
    return 0;
}
