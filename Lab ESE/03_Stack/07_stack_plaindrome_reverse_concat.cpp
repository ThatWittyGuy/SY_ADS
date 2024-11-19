#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) st.push(s[i]);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != st.top()) return false;
        st.pop();
    }
    return true;
}

string reverseString(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) st.push(s[i]);
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

string concatStrings(string s1, string s2) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < s1.length(); i++) st.push(s1[i]);
    for (int i = 0; i < s2.length(); i++) st.push(s2[i]);

    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int compareStrings(string s1, string s2) {
    stack<char> st1, st2;
    for (int i = 0; i < s1.length(); i++) st1.push(s1[i]);
    for (int i = 0; i < s2.length(); i++) st2.push(s2[i]);

    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            return st1.top() - st2.top();
        }
        st1.pop();
        st2.pop();
    }

    return st1.size() - st2.size();
}

int main() {
    string s1, s2;
    cout << "Enter a string: ";
    cin >> s1;

    cout << "Enter another string for concat and compare: ";
    cin >> s2;

    cout << "A. Palindrome: " << (isPalindrome(s1) ? "Yes" : "No") << endl;
    cout << "B. Reverse: " << reverseString(s1) << endl;
    cout << "C. Concat: " << concatStrings(s1, s2) << endl;
    cout << "D. Compare: " << compareStrings(s1, s2) << endl;

    return 0;
}



// #include <stack>
// #include <iostream>
// #include <string>
// using namespace std;

// bool isPalindrome(string s) {
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++) st.push(s[i]);
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] != st.top()) return false;
//         st.pop();
//     }
//     return true;
// }

// string reverseString(string s) {
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++) st.push(s[i]);
//     string reversed = "";
//     while (!st.empty()) {
//         reversed += st.top();
//         st.pop();
//     }
//     return reversed;
// }

// string concatStrings(string s1, string s2) {
//     return s1 + s2;
// }

// int compareStrings(string s1, string s2) {
//     return s1.compare(s2);
// }

// int main() {
//     string s1, s2;
//     cout << "Enter a string: ";
//     cin >> s1;

//     cout << "Enter another string for concat and compare: ";
//     cin >> s2;

//     cout << "A. Palindrome: " << (isPalindrome(s1) ? "Yes" : "No") << endl;
//     cout << "B. Reverse: " << reverseString(s1) << endl;
//     cout << "C. Concat: " << concatStrings(s1, s2) << endl;
//     cout << "D. Compare: " << compareStrings(s1, s2) << endl;

//     return 0;
// }
