// http://www.spoj.com/problems/JULKA/

#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

class BigInt {
private:    
    vector<int> num;
    static constexpr int kBaseDigit = 8;
    static constexpr int kBase = pow(10, kBaseDigit);    
public:
    BigInt() = default;
    
    BigInt(string s) {
        for (int i = s.size()-1; i >= 0; i -= kBaseDigit) {
            int beg = max(0, i - kBaseDigit + 1);
            num.push_back(stoi(s.substr(beg, i - beg + 1)));
        }
    }

    BigInt(long long i) {
        do {
            num.push_back(i % kBase);
            i /= kBase;
        } while (i);
    }

    void operator = (const BigInt& b) {
        num = b.num;
    }

    BigInt operator + (BigInt& b) {
        BigInt res;
        int i = 0, j = 0, carry = 0;
        while (i < num.size() || j < b.num.size() || carry) {
            int l = i < num.size() ? num[i++] : 0;
            int r = j < b.num.size() ? b.num[j++] : 0;
            long n = static_cast<long>(l) + r + carry;
            res.num.push_back(n % kBase);
            carry = n / kBase;
        }
        return res;
    }

    BigInt operator - (BigInt& b) {
        BigInt res = *this;
        int carry = 0;
        for (int i = 0; i < b.num.size() || carry; i++) {
            res.num[i] -= i < b.num.size() ? b.num[i] : 0;            
            res.num[i] -= carry;
            carry = res.num[i] < 0 ? 1 : 0;
            if (carry) {
                res.num[i] += kBase;
            } 
        }
        return res;
    }

    BigInt operator / (int v) {
        BigInt res = *this;
        long long rem = 0;
        for (int i = res.num.size()-1; i >= 0; i--) {
            long long cur = res.num[i] + rem * kBase;
            res.num[i] = cur / v;
            rem = cur % v;
        }
        return res;
    }

    friend ostream& operator<< (ostream& out, const BigInt& b) {
        if (!b.num.empty()) {
            out << b.num.back();
            for (int i = b.num.size() - 2; i >= 0; i--) {
                out << setw(kBaseDigit) << setfill('0') << b.num[i];
            }
        } else {
            out << "0";
        }
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    for (int i = 0; i < 10; i++) {
        cin >> s1 >> s2;
        BigInt a(s1), b(s2);
        BigInt c = (a + b) / 2;
        cout << c << '\n';
        cout << c - b << '\n';
    }
    
    return 0;
}