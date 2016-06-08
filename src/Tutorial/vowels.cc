// http://www.spoj.com/problems/VOWELS/

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    size_t found = s.find_first_of("aeiouAEIOU");
    int count = 0;
    while (found != string::npos) {
        count++;
        found = s.find_first_of("aeiouAEIOU", found + 1);
    }
    cout << count << endl;
    return 0;
}
