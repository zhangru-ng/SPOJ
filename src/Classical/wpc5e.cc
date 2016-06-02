// http://www.spoj.com/problems/WPC5E/

#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x;
    double y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator - (const Point &p) {
        return Point(x - p.x, y - p.y);
    }

    double det(const Point& p) {
        return x * p.y - y * p.x;
    }
};

vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size();
    vector<Point> ch(2 * n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 1 && (ch[k-1] - ch[k-2]).det(points[i] - ch[k-1]) <= 0) {
            k--;
        }
        ch[k++] = points[i];
    }
    int t = k;
    for (int i = n - 2; i >= 0; i--) {
        while (k > t && (ch[k-1] - ch[k-2]).det(points[i] - ch[k-1]) <= 0) {
            k--;
        }
        ch[k++] = points[i];
    }
    ch.resize(k-1);
    return ch;
}

double dist(const Point& p1, const Point& p2) {
    return abs(p1.x * p1.x - p2.x * p2.x) + abs(p1.y * p1.y - p2.y * p2.y);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<Point> points;
        int a;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            points.emplace_back(i, a);
        }

        vector<Point> ch = convex_hull(points);
        double res = 0;
        for (int i = 0; i < ch.size(); i++) {
            for (int j = 0; j < ch.size(); j++) {
                res = max(res, dist(ch[i], ch[j]));
            }
        }
        printf("%.0f\n", res);
    }
    return 0;
}
