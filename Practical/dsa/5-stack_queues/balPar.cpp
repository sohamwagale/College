#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    stack<char> s1;
    string str = "(()(())))))()";

    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            s1.push('(');
        }
        else if(str[i]==')'){
            if(!s1.empty() && s1.top()=='('){
                s1.pop();
            }
            else{
                s1.push(')');
            }
        }
    }

    cout<<s1.size();
}