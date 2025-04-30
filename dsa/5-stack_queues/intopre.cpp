#include <bits/stdc++.h>
using namespace std;

int priority(char operat) {
    if (operat == '^') return 3;  // Highest precedence for ^
    if (operat == '*' || operat == '/') return 2;
    if (operat == '+' || operat == '-') return 1;
    return -1;
}

void infixToPrefix(string &s) {
    // Step 1: Reverse the expression
    reverse(s.begin(), s.end());

    // Step 2: Swap the parentheses
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    // Step 3: Convert the expression to postfix
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i])) {
            ans += s[i];  // Operand, append it to the result
        } else if (s[i] == '(') {
            st.push(s[i]);  // Push '(' to stack
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();  // Pop '(' from stack
        } else {  // Operator
            if (s[i] == '^') {//Right associative asla tar equal wala pan pop karaycha
                // For '^', pop operators with lower precedence, AND '^' itself (right-associative)
                while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            } else {// For other operators, pop if precedence is less than
                while (!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }  
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Step 4: Reverse the postfix expression to get prefix
    reverse(ans.begin(), ans.end());
    cout << "Prefix Expression: " << ans << endl;
}

int main() {
    string s;
    cout << "Enter the Expression: ";
    cin >> s;
    
    cout << "Infix to Prefix Conversion: " << endl;
    infixToPrefix(s);

    return 0;
}
