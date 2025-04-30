#include<iostream>
using namespace std;

int main(){
    long long num = 0;
    cout<<"Enter Number : ";
    cin>>num;
    int rem = 0;
    long long rev = 0;
    while(num>0){
        rem = num%10;
        rev=(rev*10)+rem;
        num/=10;
    }
    cout<<"The reversed number is :"<<rev;
    return 0;
}