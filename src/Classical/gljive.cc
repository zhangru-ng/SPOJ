// http://www.spoj.com/problems/GLJIVE/

#include <iostream>
using namespace std;

int main(){
    int num;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        if (sum + num >= 100) {
            cout << (100 - sum < sum + num - 100 ? sum : sum + num) << "\n";
            return 0;
        }
        sum += num;
    }
    cout << sum << "\n";
    return 0;
}
