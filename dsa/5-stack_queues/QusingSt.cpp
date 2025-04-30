#include<bits/stdc++.h>
using namespace std;

class Que{
public:
    stack<int> s1,s2;

    void push(int elem){
        while (s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(elem);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }

    int top(){
        return s1.top();
    }


};

int main(){
    Que q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    cout << q.top();
    q.pop();
    cout << q.top();
    q.pop();
    cout << q.top();
    q.pop();
    cout << q.top();
}