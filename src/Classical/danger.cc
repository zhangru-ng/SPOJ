// http://www.spoj.com/problems/DANGER/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    while (s != "00e0") {
        int n = ((s[0]-'0') * 10 + s[1]-'0') * pow(10, s[3]-'0');
        int x = pow(2, static_cast<int>(log2(n)));
        cout << 2*(n-x) + 1 << "\n";
        getline(cin, s);
    }
    return 0;
}
