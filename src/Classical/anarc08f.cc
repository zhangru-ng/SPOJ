// http://www.spoj.com/problems/ANARC08F/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (true) {
        int n, c, r;
        cin >> n >> c >> r;
        if (n == 0 && c == 0 && r == 0) {
            break;
        }

        unordered_map<string, int> mp;
        string garage;
        cin >> garage;
        mp.emplace(garage, 0);

        int idx = 1;
        vector<string> broken_cars;
        for (int i = 0; i < c; i++) {
            string name;
            cin >> name;
            broken_cars.push_back(name);
            if (mp.find(name) == mp.end()) {
                mp.emplace(name, idx++);
            }
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX/2));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < r; i++) {
            string name1, edge, name2;
            cin >> name1 >> edge >> name2;
            if (mp.find(name1) == mp.end()) {
                mp.emplace(name1, idx++);
            }
            if (mp.find(name2) == mp.end()) {
                mp.emplace(name2, idx++);
            }
            int u = mp[name1];
            int v = mp[name2];
            int w = stoi(edge.substr(2, edge.size()-4));
            if (edge[0] == '<' && dist[v][u] > w) {
                dist[v][u] = w;
            }
            if (edge.back() == '>' && dist[u][v] > w) {
                dist[u][v] = w;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int tot_dist = 0;
        for (string& name : broken_cars) {
            int v = mp[name];
            tot_dist += dist[0][v] + dist[v][0];
        }
        cout << t << ". " << tot_dist << endl;
        t++;
    }
    return 0;
}
