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
    s = "pq+mn-*";
    //s = "a+b";
    cout<<"Enter the Expression"<<endl;
    cin>>s;
    cout<<"Calculating for exp :"<<s<<endl;
    int n = s.size();
    stack<string> st;
    string ans = "";
    int i = 0;
    while(i<n){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string nt= "("+ t2 + s[i] + t1 + ")";
            st.push(nt);
        }
        i++;
    }
    cout<<st.top();
}