// http://www.spoj.com/problems/NHAY/

#include <iostream>
#include <vector>
using namespace std;

vector<int> buildTable(string& P) {
    int m = P.size();
    vector<int> prefunc(m, 0);
    for (int i = 1; i < m; i++) {
        int j = prefunc[i-1];
        while (j > 0 && P[i] != P[j]) {
            j = prefunc[j-1];
        }
        if (P[i] == P[j]) {
            j++;
        }
        prefunc[i] = j;
    }
    return prefunc;
}

void KMP(string T, string P) {
    if (P.empty()) {
        return;
    }
    int n = T.size(), m = P.size();
    vector<int> prefunc = buildTable(P);
    int j = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) {
            j = prefunc[j-1];
        }
        if (T[i] == P[j]) {
            j++;
        }
        if (j == m) {
            found = true;
            cout << i - m + 1 << endl;
            j = prefunc[j-1];
        }
    }
    if (found) {
        cout << endl;
    }
}

int main() {
    int n;
    while (cin >> n) {
        string T, P;
        cin >> P >> T;
        KMP(T, P);
    }
}
