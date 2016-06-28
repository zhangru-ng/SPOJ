// http://www.spoj.com/problems/QUADAREA/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        double s = 0.5 * (a + b + c + d);
        cout << fixed << setprecision(2) << sqrt((s-a) * (s-b) * (s-c) * (s-d)) << "\n";
    }

    return 0;
}
