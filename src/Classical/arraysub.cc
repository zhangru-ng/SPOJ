// http://www.spoj.com/problems/ARRAYSUB/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int k;
    cin >> k;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && vec[i] > vec[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1) {
            cout << vec[dq.front()] << " ";
        }
        if (dq.front() <= i-k+1) {
            dq.pop_front();
        }
    }
    cout << endl;
    return 0;
}
