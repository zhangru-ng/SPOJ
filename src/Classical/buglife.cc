// http://www.spoj.com/problems/BUGLIFE/

#include <iostream>
#include <vector>
using namespace std;

struct Vertex {
    int state;
    vector<int> adj_list;
    Vertex() : state(-1) {}
};

int dfs(vector<Vertex>& graph, int i, int gender) {
    graph[i].state = gender;
    for (int u : graph[i].adj_list) {
        if (graph[u].state == gender) {
            return -1;
        }
        if (graph[u].state == -1 && dfs(graph, u, !gender) == -1) {
            return -1;
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int v, e;
        cin >> v >> e;
        vector<Vertex> graph(v+1);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].adj_list.push_back(b);
            graph[b].adj_list.push_back(a);
        }
        int flag = true;
        for (int i = 1; i <= v; i++) {
            if (graph[i].state == -1 && dfs(graph, i, 1) == -1) {
                flag = false;
                break;
            }
        }
        cout << "Scenario #" << k << ":" << endl;
        cout << (flag ? "No suspicious bugs found!" : "Suspicious bugs found!") << endl;
    }
    return 0;
}
