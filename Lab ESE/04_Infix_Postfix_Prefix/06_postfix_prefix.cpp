#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string postfixToPrefix(string postfix) {
    stack<string> st;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = c + op1 + op2;
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
