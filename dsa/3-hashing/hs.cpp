#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;

    int szs = sizeof(s)/sizeof(s[0]);

//Pre calculation of hash array
	int hash[256] = {0};
	for(int i =0;i<szs;i++){
		hash[s[i]]++;
	}


//Questions
	int noq;
	cout<<"Enter Number of Questions: "<<endl;
	cin>>noq;
	cout<<"Ask questions:"<<endl;
	while(noq--){
		char c;
		cout<<"\t";
		cin>>c;
		cout<<"\tNumber of occurences of \'"<<c<<"\' are "<<hash[c]<<endl;
	}
    return 0;
}
