#include<bits/stdc++.h>
using namespace std;

void rev(int arr[],int l,int r){
	if(l>=r)
		return;
	swap(arr[l],arr[r]);
	rev(arr,l+1,r-1);	
}
int main(){
	int n;	
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
	rev(arr,0,n-1);
	for(int element : arr)
		cout<<element;
//	}
//	else cout<<"try again";
	return 0;
}

