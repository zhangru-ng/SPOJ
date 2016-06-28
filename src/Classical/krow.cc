// http://www.spoj.com/problems/KROW/

#include <iostream>
#include <vector>
using namespace std;

int play(vector<string> &games, int K) {
    int m = games.size();
    int n = m > 0 ? games[0].size() : 0;

    // check row
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n - K; j++) {
            bool fstwin = true, sndwin = true;
            for (int k = j; k < j + K; k++) {
                if (games[i][k] != 'x') {
                    fstwin = false;
                }
                if (games[i][k] != 'o') {
                    sndwin = false;
                }
            }
            if (fstwin) return 1;
            if (sndwin) return 2;
        }
    }
    // check column
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= m - K; i++) {
            bool fstwin = true, sndwin = true;
            for (int k = i; k < i + K; k++) {
                if (games[k][j] != 'x') {
                    fstwin = false;
                }
                if (games[k][j] != 'o') {
                    sndwin = false;
                }
            }
            if (fstwin) return 1;
            if (sndwin) return 2;
        }
    }

    // check diagonal
    for (int i = 0; i <= m - K; i++) {
        for (int j = 0; j <= n - K; j++) {
            bool fstwin = true, sndwin = true;
            for (int k = 0; k < K; k++) {
                if (games[i+k][j+k] != 'x') {
                    fstwin = false;
                }
                if (games[i+k][j+k] != 'o') {
                    sndwin = false;
                }
            }
            if (fstwin) return 1;
            if (sndwin) return 2;
        }
    }

    // check anti-diagonal
    for (int j = 0; j <= n - K; j++) {
        for (int i = K-1; i < m; i++) {
            bool fstwin = true, sndwin = true;
            for (int k = 0; k < K; k++) {
                if (games[i-k][j+k] != 'x') {
                    fstwin = false;
                }
                if (games[i-k][j+k] != 'o') {
                    sndwin = false;
                }
            }
            if (fstwin) return 1;
            if (sndwin) return 2;
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int hansel = 0, gretel = 0;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> games(m);
        for (int i = 0; i < m; i++) {
            cin >> games[i];
        }

        int res = play(games, k);

        if (res == 1) {
            hansel++;
        } else if (res == 2) {
            gretel++;
        }
    }
    cout << hansel << ":" << gretel << "\n";

    return 0;
}
