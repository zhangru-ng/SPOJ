// http://www.spoj.com/problems/SIGSEGV/

#include <iostream>
using namespace std;

int main() {
    int *ptr = nullptr;
    *ptr = 1;
    return 0;
}
