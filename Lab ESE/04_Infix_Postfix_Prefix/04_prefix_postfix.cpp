#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string prefixToPostfix(string prefix) {
    stack<string> st;
    
    reverse(prefix.begin(), prefix.end());
    
    for (int i = 0; i < prefix.length(); i++) {
        char c = prefix[i];
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            st.push(string(1, c));
        }
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = op1 + op2 + c;
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter a prefix expression: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
