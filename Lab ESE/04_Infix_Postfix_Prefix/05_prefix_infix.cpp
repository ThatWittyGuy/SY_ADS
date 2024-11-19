#include <stack>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string prefixToInfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string prefix;
    cout << "Enter a prefix expression: ";
    cin >> prefix;
    
    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
