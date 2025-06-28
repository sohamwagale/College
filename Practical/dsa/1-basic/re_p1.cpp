#include<bits/stdc++.h>
using namespace std;

int i=0;
int n;
void name(int n){
	if(i==n)
	return;
	cout<<"soham"<<endl;
	i++;
	name(n);
	}
int main(){
	cin>>n;
	name(n);
	return 0;
}
