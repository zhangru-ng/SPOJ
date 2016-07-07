// http://www.spoj.com/problems/CODESPTB/

#include <vector>
#include <iostream>
using namespace std;

long long mergecnt(vector<int>& v, int l, int m, int r) {
    long long cnt = 0;
    int n_left = m - l + 1;
    int n_right = r - m;

    vector<int> L(n_left);
    for (int i = 0; i < n_left; i++) {
        L[i] = v[l+i];
    }
    vector<int> R(n_right);
    for (int i = 0; i < n_right; i++) {
        R[i] = v[m+i+1];
    }

    int i = 0, j = 0, k = l;
    while (i < n_left && j < n_right) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            cnt += n_left - i;
            v[k++] = R[j++];
        }
    }

    while (i < n_left) {
        v[k++] = L[i++];
    }

    while (j < n_right) {
        v[k++] = R[j++];
    }
    return cnt;
}

long long invcnt(vector<int>& v, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int m = l + (r-l) / 2;
    long long cnt_left = invcnt(v, l, m);
    long long cnt_right = invcnt(v, m+1, r);
    long long cnt_cross = mergecnt(v, l, m, r);
    return cnt_left + cnt_right + cnt_cross;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << invcnt(v, 0, n-1) << endl;
    }

    return 0;
}
