#include<iostream>
using namespace std;

//division is 0 to mid and mid+1 to n

void merge(int* arr,int low,int mid,int high){
    int left = low;
    int right = mid+1;
    int i =0;
    int temp_arr[high-low+1];
    while(left<=mid && right<=high){
        if(arr[left]>arr[right]){
            temp_arr[i]=arr[right];
            i++;
            right++;
        }
        else {
            temp_arr[i]=arr[left];
            i++;
            left++;
        }
    }

    while(left<=mid){
        temp_arr[i]=arr[left];
        i++;
        left++;
    }

    while(right<=high){
        temp_arr[i]=arr[right];
        i++;
        right++;
    }

    for(int i = low;i<=high;i++){
        arr[i]=temp_arr[i-low];
    }
}

void merge_sort(int* arr,int low,int high){
    if(low==high) return;
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

int sza;

int main(){
    
    cout<<"Enter the size of array: ";
    cin>>sza;
    cout<<endl;
    int arr[sza];
    for(int i=0;i<sza;i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,sza-1);

    for(int nums:arr){
        cout<<nums<<" ";
    }
}