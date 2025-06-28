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
    stack<string> st;
    string ans = "";
    int i = s.size() -1;
    while(i>=0){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string nt= "("+ t1 + s[i] + t2 + ")";
            st.push(nt);
        }
        i--;
    }
    cout<<st.top();
}