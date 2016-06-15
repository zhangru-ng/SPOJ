// http://www.spoj.com/problems/FASHION/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> men(n);
        for(int i = 0; i < n; i++) {
            cin >> men[i];
        }

        vector<int> women(n);
        for(int i = 0; i < n; i++) {
            cin >> women[i];
        }

        sort(men.begin(), men.end());
        sort(women.begin(), women.end());

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += men[i] * women[i];
        }
        cout << sum << "\n";
    }
    return 0;
}
