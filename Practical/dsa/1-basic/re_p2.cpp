#include<bits/stdc++.h>
using namespace std;

int i=0,n;

void num(int n){
	if(i==n)
		return;
	cout<<i+1<<endl;
	i++;
	num(n);
}

int main(){
	cin>>n;
	num(n);
}
