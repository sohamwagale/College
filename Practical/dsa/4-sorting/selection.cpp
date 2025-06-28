#include<iostream>
using namespace std;
//O(n^2) for all
int main(){
    int sza;
    cout<<"Enter the size of array: ";
    cin>>sza;
    cout<<endl;
    int arr[sza];
    for(int i=0;i<sza;i++){
        cin>>arr[i];
    }
    for(int i=0;i<sza-1;i++){
        int mini = i;
        for(int j=i;j<sza;j++){
            if(arr[j]<arr[mini]){
                mini =j;
            }
        }
        swap(arr[mini],arr[i]);
    }
    cout<<"\n\nSorted array: \n\t";

    for(auto elems : arr){
        cout<<elems<<" ";
    }

}