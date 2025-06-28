#include<bits/stdc++.h>
using namespace std;

int main(){
    string  s = "pq+mn-*";
    //s = "a+b";
    cout<<"Enter the Expression"<<endl;
    cin>>s;
    cout<<"Calculating for exp :"<<s<<endl;
    int operatCnt =0;
    for(int i=0;i<s.size();i++){
        if(isalnum(s[i])){
            operatCnt++;
        }
        else{
            if(operatCnt< 2){
                cout<<"Isnt postfix";
                return -1;
            }
            operatCnt--;
        }
    }
    if(operatCnt ==1){
        cout<<"It is Postfix";
        return 0;
    }
    else {
        cout<<"Isnt postfix";
        return -1;
    }
}