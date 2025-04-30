#include<iostream>
using namespace std;

int main(){
    int x,y;
    cout<<"Enter x and y : ";
    cin>>x>>y;
    int pow =1;
    for(int i = 0;i<y;i++){
        pow *= x;
    }
    cout<<"\nx raised to y is : "<<pow;
    return 0;
}