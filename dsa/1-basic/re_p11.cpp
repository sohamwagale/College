#include<bits/stdc++.h>
using namespace std;

bool rev(string str,int i,int n){
	if(i>=n/2)
		return true;
	if(str[i]!=str[n-i-1])
		return false;
	return rev(str,i+1,n);
}
int main(){
	string str;
	int i=0;	
	cout<<"enter word"<<endl;
	cin>>str;
	int n= str.length();
	if(rev(str,i,n))
		cout<<"Palindrome";
	else cout<<"Not a Palindrome";
	return 0;
}

