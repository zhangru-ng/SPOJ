// http://www.spoj.com/problems/MEOWIST/

#include <iostream>
#include <algorithm>
using namespace std;

using psi_t = pair<string, int>;

int main() {
    vector<psi_t> friends;
    string name;
    int age;
    while (cin >> name >> age) {
        friends.emplace_back(name, age);
    }
    sort(friends.begin(), friends.end(), [](const psi_t& p1, const psi_t& p2) {
        if (p1.second != p2.second) {
            return p1.second > p2.second;
        } else {
            return p1.first < p2.first;
        }});
    for (auto f : friends) {
        cout << f.first << endl;
    }
    return 0;
}
