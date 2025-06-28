#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n] ;

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
   // for(int i = 0;i<n;i++){
   //     cout<<arr[i];
   // }

    int largest =0;
    int sum =0;
    int smallest = 4154534;

    for (auto num : arr){
        if(num>largest){
            largest = num;
        }     
        if(num<smallest){
            smallest = num;
        }
        sum+=num;
        
    }  


        

    cout<<"The largest element is : "<<largest<<endl;
    cout<<"The smallest element is : "<<smallest<<endl;
    cout<<"The sum of all elements is : "<<sum;

    return 0;


}