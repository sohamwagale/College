#include<bits/stdc++.h>
using namespace std;

void rev(int arr[],int i,int n){
	if(i>=n/2)
		return;
	swap(arr[i],arr[n-i-1]);
	rev(arr,i+1,n-i-2);	
}
int main(){
	int n,i=0;	
	cout<<"enter size of array"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0 ;i<n  ; i++){
		cout<<"enter element no."<<i+1<<endl;
		cin>>arr[i];
	}
//	int size = sizeof(arr)/sizeof(arr[0]);
//	if(size==n){
	cout<<"the reverse is"<<endl;
	rev(arr,i,n);
	for(int element : arr)
		cout<<element;
//	}
//	else cout<<"try again";
	return 0;
}

