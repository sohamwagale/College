#include<bits/stdc++.h>
using namespace std;

int n;

void num(int n){
	if(n==0)
		return;
	cout<<n<<endl;
	n--;
	num(n);
}

int main(){
	cin>>n;
	num(n);
}
