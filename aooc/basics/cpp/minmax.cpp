#include<iostream>
using namespace std;

int main(){
    int arr[10];
    cout<<"Enter an array : ";
    for(int i =0;i<10;i++){
        cin>>arr[i];
    }

    int max=0;
    int min=10001010;

    for(auto num : arr){
        if(num>max){
            max=num;
        }
        if(num<min){
            min = num;
        }
    }

    cout<<"\nThe greatest is : "<<max<<endl<<"\nAnd the smallest is : "<<min;

    return 0;
}