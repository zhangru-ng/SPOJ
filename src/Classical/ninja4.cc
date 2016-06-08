// http://www.spoj.com/problems/NINJA4/

#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int q = n / 4;
        int x = -2 * q;
        int y = -2 * q;

        int r = n % 4;
        if (r == 1) {
            x += n;
        } else if (r == 2) {
            x += n - 1;
            y += n;
        } else if (r == 3) {
            x -= 2;
            y += n - 1;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
