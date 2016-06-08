// http://www.spoj.com/problems/ANARC08E/

#include <cstdio>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while(a != -1 && b != -1) {
        int sum = a + b;
        if(a == 1 || b == 1) {
            printf("%d+%d=%d\n", a, b, sum);
        } else {
            printf("%d+%d!=%d\n", a, b, sum);
        }
        scanf("%d %d", &a, &b);
    }
    return 0;
}
