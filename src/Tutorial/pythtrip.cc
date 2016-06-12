// http://www.spoj.com/problems/PYTHTRIP/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ssum = a*a + b*b;
        int c = sqrt(ssum);
        if (c * c == ssum) {
            cout << "YES " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

