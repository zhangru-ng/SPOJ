// http://www.spoj.com/problems/VHELSING/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

constexpr double k = 16 - 8 * sqrt(2);

int main(){
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        cout << fixed << setprecision(4) << k * r * r * r << "\n";
    }
    return 0;
}
