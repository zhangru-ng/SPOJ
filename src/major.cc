// http://www.spoj.com/problems/MAJOR/

#include <cstdio>
#include <vector>
using namespace std;

bool voting(vector<int> &nums, int &major) {
    int count = 0;
    for (int num : nums) {
        if (count == 0) {
            major = num;
            count = 1;
        } else if (num == major) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int num : nums) {
        if (num == major) {
            count++;
        }
    }
    return count > nums.size() / 2;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        int major = 0;
        if (voting(nums, major)) {
            printf("YES %d\n", major);
        } else {
            printf("NO\n");
        }
    }
}
