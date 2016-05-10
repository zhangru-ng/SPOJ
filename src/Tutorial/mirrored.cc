// http://www.spoj.com/problems/MIRRORED/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Ready" << endl;
    while (true) {
        getline(cin, s);
        if (s == "  ") {
            break;
        }
        if (s[0] == 'b' && s[1] == 'd' ||
            s[0] == 'd' && s[1] == 'b' ||
            s[0] == 'p' && s[1] == 'q' ||
            s[0] == 'q' && s[1] == 'p') {

            cout << "Mirrored pair" << endl;
        } else {
            cout << "Ordinary pair" << endl;
        }
    }
    return 0;
}
