// http://www.spoj.com/problems/HISTOGRA/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using ull_t = unsigned long long;

ull_t LargestRect(vector<int> &hist) {
    stack<int> st;
    ull_t largest = 0;
    hist.push_back(0);
    for (int i = 0; i < hist.size(); i++) {
        while (!st.empty() && hist[i] < hist[st.top()]) {
            ull_t height = hist[st.top()];
            st.pop();
            largest = max(largest, height * (st.empty() ? i : i-1-st.top()));
        }
        st.push(i);
    }
    return largest;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (!n) {
            break;
        }
        vector<int> hist(n);
        for (int i = 0; i < n; i++) {
            cin >> hist[i];
        }
        cout << LargestRect(hist) << endl;
    }
}
