#include<bits/stdc++.h>
using namespace std;

int n,add=0;
void sum(int n,int add){
	if(n==0)
	{	cout<<add;
		return ;
	}
	sum(n-1,add+n);
}

int main(){
	cin>>n;
	sum(n,add);
	return 0;
}
