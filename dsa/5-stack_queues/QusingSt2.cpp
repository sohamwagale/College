#include<bits/stdc++.h>
using namespace std;

class Que{
    stack<int> s1,s2;

    void push(int elem){
        s1.push(elem);
    }

    void pop(){
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int top(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};