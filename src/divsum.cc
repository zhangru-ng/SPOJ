// http://www.spoj.com/problems/DIVSUM/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;

        int sum = 0;
        if (num > 1) {
            sum = 1;
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    int j = num/i;
                    sum += i == j ? i : i + j;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
