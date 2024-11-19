#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    stack<char> st;
    string result;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == ')')
            st.push(c);

        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && prec(c) < prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string exp;
    cout << "Enter an infix expression: ";
    cin >> exp;

    string prefix = infixToPrefix(exp);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
