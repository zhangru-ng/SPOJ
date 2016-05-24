// http://www.spoj.com/problems/ANAGR/

#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

using pc_t = pair<char, int>;

vector<int> get_char_count(string& s) {
    vector<int> count(26, 0);
    for (char c : s) {
        if (isalpha(c)) {
           count[tolower(c) - 'a']++;
        }
    }
    return count;
}

vector<pc_t> char_count_diff(vector<int>& cnt_a, vector<int>& cnt_b) {
    vector<pc_t> diff;
    for (int i = 0; i < 26; i++) {
        if (cnt_a[i] != cnt_b[i]) {
            diff.emplace_back(('a' + i), cnt_a[i] - cnt_b[i]);
        }
    }
    return diff;
}

int main() {
    int t;
    cin >> t;
    string a, b;
    getline(cin, a);
    while (t--) {
        getline(cin, a);
        getline(cin, b);
        vector<int> cnt_a = get_char_count(a);
        vector<int> cnt_b = get_char_count(b);

        vector<pc_t> diff = char_count_diff(cnt_a, cnt_b);
        if (diff.empty()) {
            cout << "YES\n";
            continue;
        }
        string pal, odd;
        bool is_valid = true;
        bool is_pos = diff[0].second > 0;
        for (auto& d : diff) {
            if ((d.second > 0) != is_pos) {
                is_valid = false;
                break;
            }

            int cnt = abs(d.second);
            if (cnt % 2 == 1 && !odd.empty()) {
                is_valid = false;
                break;
            }

            pal += string(cnt / 2, d.first);
            if (cnt % 2 == 1) {
                odd = d.first;
            }
        }

        if (!is_valid) {
            cout << "NO LUCK\n";
        } else {
            cout << (pal + odd + string(pal.rbegin(), pal.rend())) << "\n";
        }

    }
    return 0;
}
