// http://www.spoj.com/problems/SUMTRIAN/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> triangle(n, vector<int>());
        int m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                scanf("%d", &m);
                triangle[i].push_back(m);
            }
        }

        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        printf("%d\n", triangle[0][0]);
    }
    return 0;
}
