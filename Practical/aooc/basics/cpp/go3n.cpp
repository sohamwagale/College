#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter 3 Numbers : ";
    cin>>a>>b>>c;
    cout<<"\nThe greatest of 3 Numbers is : ";
    if(a>=b && a>=c){
        cout<<a;
    }
    else if(b>=a && b>=c){
        cout<<b;
    }
    else {
        cout<<c;
    }
    return 0;
}