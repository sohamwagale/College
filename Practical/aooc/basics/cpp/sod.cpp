#include<iostream>
using namespace std;

int main(){
    int n=0;
    cout<<"Enter a large Number : ";
    cin>>n;
    int sum =0;
    while(n>0){
        sum += n%10;
        n/=10; 
    }
    cout<<"\nThee sum of the digits of the number is : "<<sum;

    return 0;
}