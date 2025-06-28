#include<iostream>
using namespace std;
//O(n^2) for worst and avg
//O(n) for best
int main(){
    int sza;
    cout<<"Enter the size of array: ";
    cin>>sza;
    cout<<endl;
    int arr[sza];
    for(int i=0;i<sza;i++){
        cin>>arr[i];
    }
    int swapcnt =0;
    for(int i =sza;i>0;i--){
        int swapcnt =0;
        for(int j = 0;j<i-1;j++){
//          cout<<"Comparing"<<j<<" and "<<j+1<<endl;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapcnt=1;
//              cout<<"Swaping"<<j<<" and "<<j+1<<endl;
                for(auto elems : arr){
                cout<<elems<<" ";
                }
                cout<<endl;
            }
        }
        if(swapcnt==0){
            break;
        }
        cout<<"runs"<<endl;
    }
    cout<<"\n\nSorted array: \n\t";

    for(auto elems : arr){
        cout<<elems<<" ";
    }

}