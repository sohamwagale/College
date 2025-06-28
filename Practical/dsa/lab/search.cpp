#include<iostream>
using namespace std;

int n,value;

void bubble(int* arr, int size) {
    for(int i=size;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int ls(int* arr,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}

int bs(int* arr,int start,int end){
    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid]==value) return mid;
        if(arr[mid]<value) return bs(arr,mid+1,end); 
        if(arr[mid]>value) return bs(arr,start,mid-1);
    }
    return -1;
}

int main(){
    cout<<"Enter size of array : "; 
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array : \n\t";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the value to find : ";
    cin>>value;

    cout<<"\nBefore sorting, linear search : \n\t";
    cout<<"Element at index :"<<ls(arr,n);
    cout<<"\nAfter sorting, using binary search : \n\t";
    bubble(arr,n);
    cout<<"Element at index :"<<bs(arr,0,n-1);
}