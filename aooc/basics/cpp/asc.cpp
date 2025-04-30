#include<iostream>
using namespace std;


void bubble(int *arr) {
    for(int i=9;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[10] ={0};
   // int arr[10] ={2,5,3,2,5,3,5,3,6,3};
    cout<<"Enter an array : ";
    for(int i =0;i<10;i++){
        cin>>arr[i];
    }

    bubble(arr);

    cout<<endl;
    for(auto num: arr){
        cout<<num<<" ";
    }

    return 0;
}