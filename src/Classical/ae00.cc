// http://www.spoj.com/problems/AE00/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}
