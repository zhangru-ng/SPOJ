// http://www.spoj.com/problems/CALCAREA/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points.emplace_back(x, y);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += points[i].first*points[(i+1)%n].second - points[(i+1)%n].first*points[i].second;
    }
    long long area = round(0.5 * abs(sum));
    printf("%lld", area);
    return 0;
}

