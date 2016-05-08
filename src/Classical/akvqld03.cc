// http://www.spoj.com/problems/AKVQLD03/

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> ftree;
public:
    FenwickTree(int n) {
        ftree.resize(n+1, 0);
    }

    void update(int idx, int val) {
        while (idx < ftree.size()) {
            ftree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += ftree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    FenwickTree ftree(n);
    while (q--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "find") {
            cout << ftree.getSum(b) - ftree.getSum(a-1) << endl;
        } else {
            ftree.update(a, b);
        }
    }
    return 0;
}
