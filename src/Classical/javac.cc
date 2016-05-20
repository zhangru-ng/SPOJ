// http://www.spoj.com/problems/JAVAC/

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int split(string& s, vector<string>& vs) {
    int beg = 0;
    int kind = -1;
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
            t = s.substr(beg, i-beg);
            if (kind == 2 || t.empty()) {
                return 0;
            }
            beg = i+1;
            kind = 1;
            vs.push_back(t);
        } else if (isupper(s[i])) {
            t = s.substr(beg, i-beg);
            if (kind == 1 || t.empty()) {
                return 0;
            }
            beg = i;
            kind = 2;
            vs.push_back(t);
        }
    }
    t = s.substr(beg);
    if (t.empty()) {
        return 0;
    }
    vs.push_back(s.substr(beg));
    return kind;
}

string to_java_id(vector<string>& vs) {
    string res;
    for (int i = 0; i < vs.size(); i++) {
        if (i > 0) {
            vs[i][0] = toupper(vs[i][0]);
        }
        res += vs[i];
    }
    return res;
}

string to_cpp_id(vector<string>& vs) {
    string res;
    for (int i = 0; i < vs.size(); i++) {
        vs[i][0] = tolower(vs[i][0]);
        res += vs[i];
        if (i != vs.size() - 1) {
            res += '_';
        }
    }
    return res;
}

int main() {
    string s;
    while (cin >> s) {
        vector<string> parts;
        int r = split(s, parts);
        if (r == 0) {
            cout << "Error!" << endl;
        } else if (r == 1) {
            cout << to_java_id(parts) << endl;
        } else {
            cout << to_cpp_id(parts) << endl;
        }
    }
    return 0;
}
