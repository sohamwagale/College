#include<bits/stdc++.h>
using namespace std;

int n;

void num(int i,int n){
	if(i==0)
		return;
	num(i-1,n);
	cout<<i<<endl;
}

int main(){
	cout<<"Enter a Number"<<endl;
	cin>>n;
	num(n,n);
}
	
