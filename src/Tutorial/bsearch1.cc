// http://www.spoj.com/problems/BSEARCH1/

#include <cstdio>
#include <vector>
using namespace std;

int bsearch(vector<int> &seq, int target) {
    int low = 0, high = seq.size() - 1;
    while (low < high) {
        int mid = low + (high-low) / 2;
        if (seq[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return seq[high] == target ? high : -1;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    while (q--) {
        int a;
        scanf("%d", &a);
        printf("%d\n", bsearch(seq, a));
    }

    return 0;
}
