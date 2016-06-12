// http://www.spoj.com/problems/EELCS/

#include <iostream>
using namespace std;

void merge_sort(vector<int>& v, int l, int r) {
    if (r - l <= 1) {
        return;
    }

    int m = (r+l) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m, r);

    vector<int> L(m - l);
    for (int i = l; i < m; i++) {
        L[i-l] = v[i];
    }

    vector<int> R(r - m);
    for (int i = m; i < r; i++) {
        R[i-m] = v[i];
    }

    int il = 0, ir = 0;
    for (int i = l; i < r; i++) {
        if (ir == R.size() || il < L.size() && L[il] <= R[ir]) {
            v[i] = L[il++];
        } else {
            v[i] = R[ir++];
        }
    }
}

int main(){
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }

    merge_sort(nums, 0, nums.size());
    for (int n : nums) {
        cout << n << " ";
    }
    cout << "\n";
    return 0;
}

