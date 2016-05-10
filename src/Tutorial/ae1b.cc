// http://www.spoj.com/problems/AE1B/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    int total = k * s;
    vector<int> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }
    sort(boxes.begin(), boxes.end(), greater<int>());
    int count = 0;
    for (int i = 0; i < boxes.size(); i++) {
        total -= boxes[i];
        count++;
        if (total <= 0) {
            break;
        }
    }
    cout << count << endl;
    return 0;
}
