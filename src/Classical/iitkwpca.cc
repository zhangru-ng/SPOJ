// http://www.spoj.com/problems/IITKWPCA/

#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    while (t--) {
        getline(cin, s);
        stringstream ss(s);

        unordered_set<string> st;
        string u;
        while (ss >> u) {
            st.insert(u);
        }
        cout << st.size() << "\n";
    }

    return 0;
}
