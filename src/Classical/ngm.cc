// http://www.spoj.com/problems/NGM/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int r = n % 10;
    if (r) {
        cout << 1 << endl;
        cout << r << endl;
    } else {
        cout << 2 << endl;
    }
}
