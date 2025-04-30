#include<bits/stdc++.h>
using namespace std;

long long n;
long long fac(long long n){
	if(n==1)
		return 1;
	return n*fac(n-1);
}

int main(){
	cin>>n;
	cout<<fac(n)<<endl;
	return 0;
}
