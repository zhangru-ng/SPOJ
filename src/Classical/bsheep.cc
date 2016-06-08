// http://www.spoj.com/problems/BSHEEP/

#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x;
    double y;
    int idx;
    Point() {}
    Point(double x, double y, int idx) : x(x), y(y), idx(idx) {}

    Point operator - (const Point &p) {
        return Point(x - p.x, y - p.y, -1);
    }

    double det(const Point& p) {
        return x * p.y - y * p.x;
    }

    bool is_same_coor(const Point& p) {
        return x == p.x && y == p.y;
    }
};

vector<Point> remvoe_duplicate(vector<Point>& points) {
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2){
        if (p1.y != p2.y) return p1.y < p2.y;
        if (p1.x != p2.x) return p1.x < p2.x;
        else return p1.idx < p2.idx;
    });
    vector<Point> distinct_points;
    for (int i = 0; i < points.size(); i++) {
        if (i > 0 && points[i].is_same_coor(points[i-1])) {
            continue;
        }
        distinct_points.push_back(points[i]);
    }
    return distinct_points;
}

vector<int> convex_hull(vector<Point>& points) {
    int n = points.size();
    vector<int> ch(2 * n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 1 && (points[ch[k-1]] - points[ch[k-2]]).det(points[i] - points[ch[k-1]]) <= 0) {
            k--;
        }
        ch[k++] = i;
    }
    int t = k;
    for (int i = n - 2; i >= 0; i--) {
        while (k > t && (points[ch[k-1]] - points[ch[k-2]]).det(points[i] - points[ch[k-1]]) <= 0) {
            k--;
        }
        ch[k++] = i;
    }
    ch.resize(k-1);
    return ch;
}

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<Point> v;
        int x, y;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &x, &y);
            v.emplace_back(x, y, i);
        }

        if (n == 1) {
            printf("0.00\n1\n\n");
            continue;
        }

        vector<Point> points = remvoe_duplicate(v);
        vector<int> ch = convex_hull(points);
        double c = 0.0;
        int cs = ch.size();
        for (int i = 0; i < cs; i++) {
            c += dist(points[ch[(i+1) % cs]], points[ch[i]]);
        }
        printf("%.2f\n", c);
        for (int i : ch) {
            printf("%d ", points[i].idx);
        }
        printf("\n\n");
    }
    return 0;
}
