// http://www.spoj.com/problems/GNY07A/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        string s;
        cin >> m >> s;
        cout << i << " " << s.erase(m-1, 1) << endl;
    }
    return 0;
}
