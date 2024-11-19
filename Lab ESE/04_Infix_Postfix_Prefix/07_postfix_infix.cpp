#include <stack>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string postfixToInfix(string postfix) {
    stack<string> st;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    
    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
