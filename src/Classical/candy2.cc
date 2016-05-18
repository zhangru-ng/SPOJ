// http://www.spoj.com/problems/CANDY2/

#include <cstdio>
#include <queue>
using namespace std;

using pi_t = pair<int, int>;
using Minheap = priority_queue<pi_t, vector<pi_t>, greater<pi_t>>;

void push_heap(Minheap& heap, int e, int i) {
    if (heap.size() < 3) {
        heap.emplace(e, i);
    } else if (e > heap.top().first) {
        heap.pop();
        heap.emplace(e, i);
    }
}

vector<pi_t> pop_all(Minheap& heap) {
    vector<pi_t> out;
    while (!heap.empty()) {
        out.push_back(heap.top());
        heap.pop();
    }
    return out;
}

int main() {
    int n;
    scanf("%d", &n);
    // use min heap to get top 3 of each kind of candy
    Minheap h1;
    Minheap h2;
    Minheap h3;

    for (int i = 0; i < n; i++) {
        int c, s, b;
        scanf("%d %d %d", &c, &s, &b);
        push_heap(h1, c, i);
        push_heap(h2, s, i);
        push_heap(h3, b, i);
    }
    vector<pi_t> chocolate = pop_all(h1);
    vector<pi_t> strawberry = pop_all(h2);
    vector<pi_t> banana = pop_all(h3);

    int ic, is, ib;
    int max_remain = -1;

    for (int i = 0; i < 3; i++)  {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int remain = chocolate[i].first + strawberry[j].first + banana[k].first;
                if (remain > max_remain && chocolate[i].second != strawberry[j].second &&
                  strawberry[j].second != banana[k].second && chocolate[i].second != banana[k].second) {

                    max_remain = remain;
                    ic = chocolate[i].second;
                    is = strawberry[j].second;
                    ib = banana[k].second;
                }
            }
        }
    }

    printf("%d\n%d\n%d\n", ic, is, ib);
    return 0;
}
