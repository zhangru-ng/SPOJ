// http://www.spoj.com/problems/AVG/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = 0;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            sum += num;
        }
        cout << sum / n << "\n";
    }
    return 0;
}
