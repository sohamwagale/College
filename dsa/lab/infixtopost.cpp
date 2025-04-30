#include<bits/stdc++.h>
using namespace std;

int priority(char operat){
    if(operat == '^') return 3;
    if(operat == '*' || operat == '/') return 2;
    if(operat == '+' || operat == '-') return 1;
    else return -1;
}

int main(){
    string s = "(p+q)*(m-n)";
    //s = "pq+mn-*";
    //s = "a+b";
    cout<<"Enter the Expression"<<endl;
    cin>>s;
    cout<<"Calculating for exp :"<<s<<endl;
    int n = s.size();
    stack<char> st;
    string ans = "";
    for(int i = 0; i<n;i++){
        if(isalnum(s[i])){
            ans = ans + s[i];
        }
        else if (s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else {//cahr is operator
            while(!st.empty() && priority(s[i])<priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+= st.top();
        st.pop();
    }

    cout<<ans;
}