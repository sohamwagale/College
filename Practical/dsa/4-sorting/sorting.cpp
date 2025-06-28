#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void selection(int* arr,int sza){
    for(int i=0;i<sza;i++){
        int mini = i;
        for(int j=i;j<sza;j++){
            if(arr[mini]>arr[j])
                mini = j;
        }
        swap(arr[i],arr[mini]);
    }
}

void insertion(int* arr, int sza){
    for(int i=1;i<sza;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

void bubble(int* arr,int sza){
    for(int i=sza-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void merge(int* arr, int low, int mid, int high){
    int temp_arr[high-low+1];
    int left = low;
    int right = mid+1;
    int temp_cnt = 0;

    while(left<=mid &&right<=high){
        if(arr[left]<=arr[right]){
            temp_arr[temp_cnt] = arr[left];
            temp_cnt++;
            left++;
        }
        else{
            temp_arr[temp_cnt] = arr[right];
            temp_cnt++;
            right++;
        }
    }

    while(left<=mid){
        temp_arr[temp_cnt]= arr[left];
        temp_cnt++;
        left++;
    }
    
    while(right<=high){
        temp_arr[temp_cnt]= arr[right];
        temp_cnt++;
        right++;
    }

    for(int k = low;k<=high;k++){
        arr[k] =temp_arr[k-low];
    }
}

void merge_sort(int* arr,int low, int high){
    if(low==high) return;
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void quick(int* arr,int fe , int le){
    if(fe>=le){
        return;
    }
    int start = fe;
    int pivot = fe;
    int end = le;
    while(start<end){
        while(arr[start]<=arr[pivot] && start<le){
            start++;
        }
        while(arr[end]>arr[pivot] && end>fe){
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[pivot],arr[end]);
    int pi = end;
    quick(arr,fe,pi-1);
    quick(arr,pi+1,le);
}

int main(){
    vector<int> arr;
    int elem;
    cout<<"Enter the Array : ";
    while(cin>>elem){
        arr.push_back(elem);
    }
    int sza = arr.size();
    int array[sza];
    for(int i=0;i<sza;i++){
        array[i] = arr[i];
    }

//    selection(array,sza);
//    insertion(array,sza);
//    bubble(array,sza);
//    merge_sort(array,sza,0,sza-1);
    quick(array,0,sza-1);

//Output
    for(int i =0;i<sza;i++){
        cout<<array[i]<<" ";
    }

    return 0;
}