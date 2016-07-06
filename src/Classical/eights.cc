// http://www.spoj.com/problems/EIGHTS/

#include <iostream>
using namespace std;

constexpr int last3[] = {192, 442, 692, 942};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        unsigned long long k;
        cin >> k;
        cout << ((k-1) / 4) * 1000 + last3[(k-1) % 4] << '\n';
    }

    return 0;
}
