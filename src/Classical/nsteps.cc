// http://www.spoj.com/problems/NSTEPS/

#include <iostream>
using namespace std;

int num(int x) {
    return (x / 2) * 4 + x % 2;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y == x) {
            cout << num(x) << "\n";
        } else if (y == x - 2) {
            cout << num(x-2) + 2 << "\n";
        } else {
            cout << "No Number\n";
        }
    }
    return 0;
}
