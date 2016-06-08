// http://www.spoj.com/problems/NEXTODD/

#include <cstdio>
int main(){
    int n;
    while (~scanf("%d",&n)) printf("%d\n",n+1+n%2);
}
