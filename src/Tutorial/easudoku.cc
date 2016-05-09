// http://www.spoj.com/problems/EASUDOKU/

#include <cstdio>
#include <vector>
using namespace std;

bool check(vector<vector<int>> &borad, int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (borad[i][y] == n || borad[x][i] == n) {
            return false;
        }
    }
    int lx = (x / 3) * 3;
    int ly = (y / 3) * 3;
    for (int i = lx; i < lx + 3; i++) {
        for (int j = ly; j < ly + 3; j++) {
            if (borad[i][j] == n) {
                return false;
            }
        }
    }
    return true;
}

bool solve_(vector<vector<int>> &borad) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (borad[i][j] == 0) {
                for (int k = 1; k < 10; k++) {
                    if (check(borad, i, j, k)) {
                        borad[i][j] = k;
                        if (solve_(borad)) {
                            return true;
                        } else {
                            borad[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<int>> &borad) {
    if (solve_(borad)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", borad[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution\n");
    }
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<vector<int>> borad(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &borad[i][j]);
            }
        }
        solve(borad);
    }
    return 0;
}
