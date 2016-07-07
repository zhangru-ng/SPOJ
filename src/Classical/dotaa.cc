// http://www.spoj.com/problems/DOTAA/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, D;
        cin >> n >> m >> D;
        priority_queue<int> pq;
        while (n--) {
            int x;
            cin >> x;
            pq.push(x);
        }
        while (m--) {
            if (D < pq.top()) {
                pq.push(pq.top()-D);
                pq.pop();
            } else {
                break;
            }
        }
        cout << (m < 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
