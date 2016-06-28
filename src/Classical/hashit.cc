// http://www.spoj.com/problems/HASHIT/

#include <iostream>
#include <vector>
using namespace std;

#define TABLE_SIZE 101

class HashTable {
private:
    int num;
    vector<string> table;

    int hash(string& s) {
        int h = 0;
        for (int i = 0; i < s.size(); i++) {
            h = (h + static_cast<int>(s[i]) * (i+1)) % TABLE_SIZE;
        }
        return (19 * h) % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE), num(0) {}

    bool find(string& s) {
        int h = hash(s);
        for (int j = 0; j < 20; j++) {
            int temp = (h + j*j + 23*j) % TABLE_SIZE;
            if (table[temp].empty()) {
                return false;
            } else if (table[temp] == s) {
                return true;
            }
        }
        return false;
    }

    void add(string& s) {
        int h = hash(s);
        if (find(s)) {
            return;
        }
        for (int j = 0; j < 20; j++) {
            int temp = (h + j*j + 23*j) % TABLE_SIZE;
            if (table[temp].empty() || table[temp] == "#") {
                table[temp] = s;
                num++;
                break;
            }
        }
    }

    void remove(string& s) {
        int h = hash(s);
        if (!find(s)) {
            return;
        }
        for (int j = 0; j < 20; j++) {
            int temp = (h + j*j + 23*j) % TABLE_SIZE;
            if (table[temp] == s) {
                table[temp] = "#";
                num--;
                break;
            }
        }
    }

    int size() const {
        return num;
    }

    void print_each() {
        for (int i = 0; i < table.size(); i++) {
            if (!table[i].empty() && table[i] != "#") {
                cout << i << ":" << table[i] << '\n';
            }
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        HashTable hash_table;
        while (n--) {
            string s;
            cin >> s;
            string op = s.substr(0, 3);
            string key = s.substr(4);
            if (op == "ADD") {
                hash_table.add(key);
            } else {
                hash_table.remove(key);
            }
        }
        cout << hash_table.size() << "\n";
        hash_table.print_each();
    }

    return 0;
}
