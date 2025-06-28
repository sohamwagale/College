#include<iostream>
using namespace std;

int main(){
	int sza;
	cout<<"Enter the size of array: "<<endl;
	cin>>sza;
	int a[sza];
	cout<<"Enter the max element of array: "<<endl;
	int mx;
	cin>>mx;
	cout<<"Enter the array"<<endl;
	for (int i=0;i<sza;i++){
		cin>> a[i];
	}

//Pre calculation of hash array
	int hash[mx+1] = {0};
	for(int i =0;i<sza;i++){
		hash[a[i]]++;
	}


//Questions
	int noq;
	cout<<"Enter Number of Questions: "<<endl;
	cin>>noq;
	cout<<"Ask questions:"<<endl;
	while(noq--){
		int num;
		cout<<"\t";
		cin>>num;
		cout<<"\tNumber of occurences of \'"<<num<<"\' are "<<hash[num]<<endl;
	}
	return 0;
}

