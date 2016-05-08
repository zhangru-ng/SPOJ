// http://www.spoj.com/problems/SAMER08F/

#include <iostream>
using namespace std;

long numOfSquare(int n) {
    return n * (n+1) * (2*n + 1) / 6;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cout << numOfSquare(n) << "\n";
    }
    return 0;
}
