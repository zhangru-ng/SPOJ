// http://www.spoj.com/problems/VUDAAB/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b - a == c - b) {
            cout << 2 * c - b << "\n";
        } else if (c / b == b / a) {
            cout << c * c / b << "\n";
        }
    }
    return 0;
}
