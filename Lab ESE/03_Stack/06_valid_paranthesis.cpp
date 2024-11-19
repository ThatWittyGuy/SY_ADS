#include <stack>
#include <iostream>
using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    
    if (isValidParenthesis(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;
    
    return 0;
}
