#include<bits/stdc++.h>
using namespace std;

class Steck{
public:
    queue<int> q;

    void push(int elem){
        int size = q.size();
        q.push(elem);

        for(int i=0;i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int elem = q.front();
        q.pop();
        return elem;
    }

    int top(){
        return q.front();
    }

    void display(){
        int size = q.size();
        for(int i = 0;i<size;i++){
            cout<<q.front()<<" ";
            q.push(q.front());
            q.pop();
        }
    }

    int totalSize(){
        return q.size();
    }
};

int main(){
    Steck s1;
    s1.push(2);
    s1.push(3);
    s1.push(6);
    s1.push(4);
    cout<<endl<<"Topmost Element is : "<<s1.top()<<endl;
    cout<<endl<<"Popped Element is : "<< s1.pop()<<endl;
    cout<<endl<<"Total Size is :"<<s1.totalSize()<<endl;
    s1.display();
}