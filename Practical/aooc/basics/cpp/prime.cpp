#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a number :";
    cin>>num;
    bool Flag = false;
    if(num==1){
        cout<<"Nor prime nor composite";
    }

    for (int i=2;i*i<=num;i++){
        if(Flag){
            cout<<"Num is not prime";
            break;
        }
        if(num%i==0){
            Flag = true;
        }
    }
    if(!Flag){
        cout<<"Number is prime";
    }
    
    return 0;
}