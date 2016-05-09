// http://www.spoj.com/problems/TSORT/

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> count(1000001, 0);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        count[num]++;
    }

    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            printf("%d\n", i);
            count[i]--;
        }
    }
    return 0;
}
