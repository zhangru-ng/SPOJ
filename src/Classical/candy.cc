// http://www.spoj.com/problems/CANDY/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        int sum = 0;
        vector<int> candies(n);
        for (int i = 0; i < n; i++) {
            cin >> candies[i];
            sum += candies[i];
        }
        int avg = sum / n;

        if (avg * n != sum) {
            cout << -1 << endl;
        } else {
            int res = 0;
            for (int c : candies) {
                if (c > avg) {
                    res += c - avg;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
