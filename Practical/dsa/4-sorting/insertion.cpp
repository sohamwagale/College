#include<iostream>
using namespace std;
//O(n^2) for worst and avg
//O(n) for best

void insertion(int* arr,int sza){
    for(int i = 1;i<sza;i++){
        for(int j =i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}



int main(){
    int sza;
    cout<<"Enter the size of array: ";
    cin>>sza;
    cout<<endl;
    int arr[sza];
    for(int i=0;i<sza;i++){
        cin>>arr[i];
    }
    //for(int i=0;i<sza;i++){
    //    int j=i;
    //    while(j>0 && arr[j-1]>arr[j]){
    //        swap(arr[j],arr[j-1]);
    //        j--;
    //    }
    //}
    insertion(arr,sza);

    cout<<"\n\nSorted array: \n\t";

    for(auto elems : arr){
        cout<<elems<<" ";
    }

}