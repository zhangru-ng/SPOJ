// http://www.spoj.com/problems/ONP/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    string expr;
    while (t--) {
        cin >> expr;
        string rpn;
        stack<char> op;
        for (char c : expr) {
            if (isalpha(c)) {
                rpn += c;
            } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                op.push(c);
            } else if (c == ')') {
                rpn += op.top();
                op.pop();
            }
        }
        cout << rpn << "\n";
    }
    return 0;
}
