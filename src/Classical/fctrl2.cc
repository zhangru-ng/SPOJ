// http://www.spoj.com/problems/FCTRL2/

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class BigInt {
    vector<int> num;
    const int base = 100000000;
public:
    BigInt(int i) {
        do {
            num.push_back(i % base);
            i /= base;
        } while (i);
    }

    void operator *= (int v) {
        int carry = 0;
        for (int i = 0; i < num.size() || carry; i++) {
            if (i == num.size()) {
                num.push_back(0);
            }
            long long n = static_cast<long long>(num[i]) * v + carry;
            carry = static_cast<int>(n / base);
            num[i] = static_cast<int>(n % base);
        }
        trim();
    }

    void trim() {
        while(num.back() == 0 && num.size() > 1) {
            num.pop_back();
        }
    }

    friend ostream& operator<< (ostream& out, const BigInt& b) {
        if (!b.num.empty()) {
            out << b.num.back();
            for (int i = b.num.size() - 2; i >= 0; i--) {
                out << setw(8) << setfill('0') << b.num[i];
            }
        } else {
            out << "0";
        }
        return out;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        BigInt v(1);
        for (int i = 2; i <= n; i++) {
            v *= i;
        }
        cout << v << endl;
    }
    return 0;
}
