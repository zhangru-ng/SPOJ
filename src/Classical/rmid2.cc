// http://www.spoj.com/problems/RMID2/

#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int> max_heap;

        int n;
        while (true) {
            scanf("%d", &n);
            if (n == 0) {
                printf("\n");
                break;
            } else if (n == -1) {
                printf("%d\n", max_heap.top());
                max_heap.pop();
                if (max_heap.size() < min_heap.size()) {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            } else {
                max_heap.push(n);
                min_heap.push(max_heap.top());
                max_heap.pop();
                if (max_heap.size() < min_heap.size()) {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
        }
    }
    return 0;
}
