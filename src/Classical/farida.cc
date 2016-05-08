// http://www.spoj.com/problems/FARIDA/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> readInput() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    return coins;
}

long long maxCoins() {
    vector<int> coins = readInput();

    long long robCur = 0;
    long long notRobCur = 0;

    for (int c : coins) {
        long long temp = robCur;
        robCur = notRobCur + c;
        notRobCur = max(temp, notRobCur);
    }
    return max(robCur, notRobCur);
}

int main() {
    int C;
    cin >> C;
    for (int i = 1; i <= C; i++) {
        cout << "Case " << i << ": " << maxCoins() << endl;
    }
    return 0;
}
