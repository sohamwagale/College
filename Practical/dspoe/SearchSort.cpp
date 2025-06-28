#include<iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

/*
    1. Write a program to search an element in an array using linear search. Take input an array and search an element from the user. 

    2. Write a program to search an element in an array using binary search. Take input an array and search an element from the user. 

    4. Write a program to sort an array using bubble sort. Take input an array from the user. 

    5. Write a program to sort an array using insertion sort. Take input an array from the user.

    6. Write a program to sort an array using selection sort. Take input an array from the user. 

    7. Write a program to sort an array using merge sort. Take input an array from the user. 

    8. Write a program to sort an array using quick sort. Take input an array from the user. 
    
*/

int linearSearch(vector<int> arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> arr,int start,int end,int num){
    if(start>end) return -1;
    int mid = (start+end)/2;
    if(arr[mid]==num) return mid;
    if(arr[mid]<num) return binarySearch(arr,mid+1,end,num);
    if(arr[mid]>num) return binarySearch(arr,start,mid-1,num);
}

vector<int> bubbleSort(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]) 
                swap(arr[j],arr[j+1]);
        }
    }
    return arr;
}

vector<int> insertionSort(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]) 
                swap(arr[j],arr[j+1]);
        }
    }
    return arr;
}

vector<int> selectionSort(vector<int> arr){
    int i,j;
    for(i=0;i<arr.size();i++){
        int min = i;
        for(j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min]) min = j;
        }
        swap(arr[min],arr[i]);
    }
    return arr;
}

vector<int> merge(vector<int> left,vector<int> right){
    int lc = 0;
    int rc = 0;
    vector<int> ma;
    while((lc<left.size()) && (rc<right.size())){
        if(left[lc]<=right[rc]){
            ma.push_back(left[lc++]);
        }
        else{
            ma.push_back(right[rc++]);
        }
    }
    while((lc<left.size())){
        ma.push_back(left[lc++]);
    }
    while(rc<right.size()){
        ma.push_back(right[rc++]);
    }
    return ma;
}

vector<int> mergeSort(vector<int> arr){
    if (arr.size()<=1) return arr;
    int mid = (arr.size())/2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    return merge(mergeSort(left),mergeSort(right));
}

void merge(int *arr,int start,int mid,int end){
    int left = start;
    int right = mid+1;

    int mergeArray[end-start+1]; 
    int temp = 0;

    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            mergeArray[temp++] = arr[left++];
        }
        else{
            mergeArray[temp++] = arr[right++];
        }
    }

    while(left<=mid){
        mergeArray[temp++] = arr[left++];
    }

    while(right<=end){
        mergeArray[temp++] = arr[right++];
    }

    for(int i=0;i<end-start+1;i++){
        arr[start+i] = mergeArray[i];
    }
}

void mergeSort(int *arr,int start,int end){
    if(start>=end) return;
    int mid = (start+end)/2;

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

void quickSort(int *arr,int fe,int le){
    if(fe>=le) return;
    int pivot = fe;
    int left = fe;
    int right = le;

    while(left<right){
        while(arr[left]<=arr[pivot] &&left<le){
            left++;
        }
        while(arr[pivot]<arr[right] &&right>fe){
            right--;
        }
        if(left<right){
            swap(arr[left],arr[right]);    
        }
    }
    int partitionIndex = right;
    swap(arr[right],arr[pivot]);
    quickSort(arr,fe,partitionIndex-1);
    quickSort(arr,partitionIndex+1,le);
}

int lomutoPartition(int arr[], int fe, int le) {
    int pivot = arr[le];  // pivot is the last element
    int i = fe - 1;

    for (int j = fe; j < le; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[le]);  // place pivot at correct position
    return i + 1;
}

// Quicksort using Lomuto Partition
void quickSort(int arr[], int fe, int le) {
    if (fe < le) {
        int p = lomutoPartition(arr, fe, le);
        quickSort(arr, fe, p - 1);  // sort left of pivot
        quickSort(arr, p + 1, le);  // sort right of pivot
    }
}

void qs(int *arr,int fe,int le){
    if(fe>=le) return;
    int i=fe;
    int j=le;
    int pivot = fe;
    //finding the correct index
    while(i<j){
        while(arr[i]<=arr[pivot] && i<le){//equal ones too on left side
            i++;
        }
        while(arr[j]>arr[pivot] && j>fe){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        } //i  is at the point where the elemnets are greater than pivot and j is at the pojnt where the lements are less than or equal to pivot
        //if the 
    }
    int pi = j;
    //placing ad correct index
    swap(arr[pivot],arr[pi]);
    
    qs(arr,fe,pi-1);
    qs(arr,pi+1,le);
}

int main(){
    vector<int> arr = {4,3,2,3,43,3,43,3,412,4,2,134,3};
    int arr2[] = {4,3,2,3,43,3,43,3,412,4,2,134,3};
    cout<< linearSearch(arr,43)<<endl;
    cout<< binarySearch(bubbleSort(arr),0,12,43)<<endl;
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    mergeSort(arr);
    mergeSort(arr2,0,12);
    quickSort(arr2,0,12);
    for(int num: arr2){
        cout<<num<<" ";
    }
}
