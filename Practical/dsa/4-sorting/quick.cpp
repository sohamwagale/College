#include<iostream>
using namespace std;

void qs(int *arr,int fe,int le){
    if (fe >= le){
        return;
    }
    int pivot = fe;
    int i = fe;
    int j = le;
    while(i<j){//jopryent false hota nahi topryant
        while(arr[i]<= arr[pivot] && i<=le-1){
            i++;
        }
        while(arr[j]>arr[pivot] && j>=fe+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
//Dont forget to set the new partition index. The old Pivot becomes the new partition index
    int pi = j;
    swap(arr[j],arr[pivot]);
    qs(arr,fe,pi-1);
    qs(arr,pi+1, le);

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
    qs(arr,0,sza-1);

    for(auto elems : arr){
        cout<<elems<<" ";
    }
}

